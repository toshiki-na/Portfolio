#include "EnemyMovementComputer.h"
#include <DXLib.h>
#include "../../../Constant/InitialValue.h"
#include "../../../Utility/Vec3.h"
#include "../../../TimeManager/TimeManager.h"
#include "../../../ResourceManager/ResourceSystemManager.h"
#include "../../../ResourceManager/ModelResourceManager.h"
#include "../../../Component/State/StateComponent.h"
#include "../../../Component/Transform/TransformComponent.h"

//入力アクションの実行
void EnemyMovementComputer::InputAction()
{
	//現在の状態取得
	StateType now_state = state->GetState();

	//攻撃入力
	if ((*player_position - transform->GetPosition()).LengthSq() <= enemy_attack_range * enemy_attack_range)
	{
		//待機中か移動中なら攻撃状態に
		if (now_state == StateType::Idle || now_state == StateType::Move)
		{
			state->ChangeState(StateType::Attack01);
		}
	}
}

//移動の実行
void EnemyMovementComputer::Move()
{
	if (transform != nullptr && state != nullptr)
	{
		//現在の状態取得
		StateType now_state = state->GetState();

		//待機中、移動中なら移動可能
		if (now_state == StateType::Idle || now_state == StateType::Move)
		{
			//移動方向の取得
			Vec3 move_vec = CalculateMoveVec();

			//移動方向がある時
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
Vec3 EnemyMovementComputer::CalculateMoveVec()
{
	//計算結果
	Vec3 result;

	//プレイヤー方向ベクトル
	result = (*player_position) - transform->GetPosition();

	//正規化
	if (result.LengthSq() > 0.0f)
	{
		result = result.Normalized();
	}

	//移動方向ベクトルを返す
	return result;
}