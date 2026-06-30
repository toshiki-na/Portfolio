#include "PlayerMovementComputer.h"
#include <DXLib.h>
#include "../../../Constant/InitialValue.h"
#include "../../../Utility/Vec3.h"
#include "../../../TimeManager/TimeManager.h"
#include "../../../ResourceManager/ResourceSystemManager.h"
#include "../../../ResourceManager/ModelResourceManager.h"
#include "../../../Character/ICharacterInput.h"
#include "../../../Component/State/StateComponent.h"
#include "../../../Component/Transform/TransformComponent.h"

//入力アクションの実行
void PlayerMovementComputer::InputAction()
{
	//現在の状態取得
	StateType now_state = state->GetState();

	//攻撃入力
	if (input->GetAttackInput() == true)
	{
		//待機中か移動中なら攻撃状態に
		if (now_state == StateType::Idle || now_state == StateType::Move)
		{
			state->ChangeState(StateType::Attack01);
		}
	}
}

//移動の実行
void PlayerMovementComputer::Move()
{
	if (transform != nullptr && state != nullptr)
	{
		//現在の状態取得
		StateType now_state = state->GetState();

		//待機中、移動中、ジャンプ中、回避中なら移動可能
		if (now_state == StateType::Idle || now_state == StateType::Move || now_state == StateType::Jump || now_state == StateType::Avoid)
		{
			//移動方向の取得
			Vec3 move_vec = CalculateMoveVec();

			//移動入力がある時
			if (move_vec.LengthSq() > 0.0f)
			{
				//静止状態なら移動状態に
				if (now_state == StateType::Idle)
				{
					state->ChangeState(StateType::Move);
				}
				//向き調整
				transform->SetForward(move_vec);
				transform->SetYawRadian(atan2f(-move_vec.x, -move_vec.z));

				//現在位置を計算用に保存
				Vec3 now_position = transform->GetPosition();

				//次フレームの移動先計算
				Vec3 next_position = now_position + (move_vec * speed * TimeManager::Instance().GetDeltaTime());

				//地形との衝突判定
				//地形のモデルハンドル取得
				ModelResourceManager& model_resource_manager = ResourceSystemManager::Instance().GetModelManager();
				int wall_handle = model_resource_manager.GetHandle(ModelTag::Wall);
				int ground_hande = model_resource_manager.GetHandle(ModelTag::Ground);

				//壁との衝突判定
				DxLib::MV1_COLL_RESULT_POLY wall_coll_result = DxLib::MV1CollCheck_Line(wall_handle, -1, (now_position + coll_adjust_up_vector).ToDXLibVECTOR(), (next_position + (move_vec * character_radius) + coll_adjust_up_vector).ToDXLibVECTOR());

				//当たっていたら壁の手前で停止
				if (wall_coll_result.HitFlag == 1)
				{
					Vec3 wall_coll_position;
					wall_coll_position.x = wall_coll_result.HitPosition.x;
					wall_coll_position.y = 0.0f;
					wall_coll_position.z = wall_coll_result.HitPosition.z;

					next_position = wall_coll_position - (move_vec * character_radius);
				}

				//床との衝突判定
				DxLib::MV1_COLL_RESULT_POLY ground_coll_result = DxLib::MV1CollCheck_Line(ground_hande, -1, (next_position + coll_adjust_up_vector).ToDXLibVECTOR(), (next_position + coll_adjust_down_vector).ToDXLibVECTOR());

				//当たっていたらその地点が次の移動地点
				if (ground_coll_result.HitFlag == 1)
				{
					Vec3 ground_coll_position;
					ground_coll_position.x = ground_coll_result.HitPosition.x;
					ground_coll_position.y = ground_coll_result.HitPosition.y;
					ground_coll_position.z = ground_coll_result.HitPosition.z;

					next_position = ground_coll_position;
				}

				//移動確定
				transform->SetPosition(next_position);
			}
			//移動入力が無いとき
			else
			{
				//移動中なら静止状態に
				if (now_state == StateType::Move)
				{
					state->ChangeState(StateType::Idle);
				}
			}
		}
	}
}

//移動方向の計算
Vec3 PlayerMovementComputer::CalculateMoveVec()
{
	//計算結果
	Vec3 result;

	//上下左右の入力
	Vec3 input_vec = input->GetMoveInput();

	//カメラ前方ベクトルがヌルなら入力をそのまま移動に
	if (camera_position_form_target_vector == nullptr)
	{
		result.x = input_vec.x;
		result.y = 0.0;
		result.z = input_vec.y;
	}
	//カメラローカル座標系と入力ベクトルからワールド座標系での移動方向を計算
	else
	{
		//カメラ前方ベクトルはカメラの注視点から位置ベクトルの逆ベクトル
		Vec3 camera_forward = (*camera_position_form_target_vector).Negative();

		//カメラローカル座標系の前方と入力の前後からワールド座標系での前方入力を計算
		Vec3 forward = camera_forward * input_vec.y;

		//カメラローカル座標系の前方と入力の左右からワールド座標系での右方入力を計算(左手系空間なので右方向は上方向ベクトル×前方向ベクトル)
		Vec3 right = Vec3Math::Cross(up_vector, camera_forward) * input_vec.x;

		//前方ベクトルと右方ベクトルの線形結合で移動方向ベクトル計算
		result = forward + right;

		//y軸方向は移動しないので補正
		result.y = 0.0f;
	}

	//正規化
	if (result.LengthSq() > 0.0f)
	{
		result = result.Normalized();
	}

	//移動方向ベクトルを返す
	return result;
}