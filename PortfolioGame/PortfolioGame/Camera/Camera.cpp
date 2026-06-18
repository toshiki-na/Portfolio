#include "Camera.h"
#include <DxLib.h>
#include "../Constant/InitialValue.h"
#include "../Utility/Vec3.h"
#include "../Component/Transform/TransformComponent.h"
#include "../ResourceManager/ResourceSystemManager.h"
#include "../ResourceManager/ModelResourceManager.h"

//初期化
void Camera::Initialize(TransformComponent* target_)
{
	if (target_ != nullptr) //ヌルチェック
	{
		//注視点を設定
		target = target_;

		//注視点補正(高さ上げ)
		Vec3 correct_target_position = target->GetPosition() + camera_target_offset;

		//カメラ位置を計算
		position = correct_target_position + (position_from_target * distance_form_target);

		//座標と注視点、上方向を指定
		DxLib::SetCameraPositionAndTargetAndUpVec(position.ToDXLibVECTOR(), correct_target_position.ToDXLibVECTOR(), up_vector.ToDXLibVECTOR());
	}
	else
	{
		//ターゲット不明なら暫定位置にカメラ移動
		DxLib::SetCameraPositionAndTargetAndUpVec(Vec3(0.0f, 100.0f, 100.0f).ToDXLibVECTOR(), Vec3::Zero().ToDXLibVECTOR(), up_vector.ToDXLibVECTOR());
	}

	//視野の最近距離と最遠距離を設定
	DxLib::SetCameraNearFar(vision_near, vision_far);

	//視野角を初期値に
	DxLib::SetupCamera_Perspective(fov * DIGREE_TO_RADIAN);
}

//更新
void Camera::Update()
{
	//回転
	Rotate();

	//移動
	Move();
}

//視野角変更
void Camera::ChangeFoV(float new_fov_)
{
	float radian_fov = new_fov_ * DIGREE_TO_RADIAN;
	DxLib::SetupCamera_Perspective(radian_fov);
	fov = new_fov_;
}

//操作入力切り替え
void Camera::ChangeInput(std::unique_ptr<ICameraInput> new_input_)
{
	input = std::move(new_input_);
}

//移動
void Camera::Move()
{
	if (target != nullptr) //ヌルチェック
	{
		//注視点補正(高さ上げ)
		Vec3 adjust_target_position = target->GetPosition() + camera_target_offset;

		//次フレームのカメラ位置を計算
		Vec3 next_position = adjust_target_position + (position_from_target * distance_form_target);

		//地形との衝突判定
		//地形のモデルハンドル取得
		int wall_model_handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Wall);
		int ground_model_hande = ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Ground);


		//壁との衝突判定
		DxLib::MV1_COLL_RESULT_POLY wall_coll_result = DxLib::MV1CollCheck_Line(wall_model_handle, -1, position.ToDXLibVECTOR(), next_position.ToDXLibVECTOR());

		//当たっていたら壁の手前で停止
		if (wall_coll_result.HitFlag == 1)
		{
			Vec3 wall_coll_position;
			wall_coll_position.x = wall_coll_result.HitPosition.x;
			wall_coll_position.y = wall_coll_result.HitPosition.y;
			wall_coll_position.z = wall_coll_result.HitPosition.z;

			next_position = adjust_target_position + (position_from_target * (distance_form_target - (wall_coll_position - next_position).Length()));
		}

		//床との衝突判定
		DxLib::MV1_COLL_RESULT_POLY ground_coll_result = DxLib::MV1CollCheck_Line(ground_model_hande, -1, position.ToDXLibVECTOR(), next_position.ToDXLibVECTOR());

		//当たっていたらその地点が次の移動地点
		if (ground_coll_result.HitFlag == 1)
		{
			Vec3 ground_coll_position;
			ground_coll_position.x = ground_coll_result.HitPosition.x;
			ground_coll_position.y = ground_coll_result.HitPosition.y;
			ground_coll_position.z = ground_coll_result.HitPosition.z;

			next_position = adjust_target_position + (position_from_target * (distance_form_target - (ground_coll_position - next_position).Length()));
		}

		//座標と注視点、上方向を指定
		DxLib::SetCameraPositionAndTargetAndUpVec(next_position.ToDXLibVECTOR(), adjust_target_position.ToDXLibVECTOR(), up_vector.ToDXLibVECTOR());
	}
}

//回転
void Camera::Rotate()
{
	if (input == nullptr) //ヌルチェック
	{
		return;
	}

	//入力取得
	Vec3 input_delta = input->GetLookInput();

	//視点感度反映
	input_delta *= sensitivity;

	//ヨー角加算(マウス移動と逆回転させたいので減算)
	yaw_angle -= input_delta.x;

	//ピッチ角加算(マウス移動と逆回転させたいので減算)
	pitch_angle -= input_delta.y;

	//ピッチ角の上下限範囲内調整
	if (pitch_angle > pitch_angle_limit)
	{
		pitch_angle = pitch_angle_limit;
	}
	if (pitch_angle < -pitch_angle_limit)
	{
		pitch_angle = -pitch_angle_limit;
	}

	//ピッチ角とヨー角から注視点からの位置ベクトルを計算
	position_from_target.x = sinf(yaw_angle);
	position_from_target.y = sinf(pitch_angle);
	position_from_target.z = -cosf(yaw_angle);
}