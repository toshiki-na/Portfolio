#include "Camera.h"
#include <DxLib.h>
#include "../Constant/ConstantValue.h"
#include "../Utility/Vec3.h"

//初期化
void Camera::Initialize()
{
	//カメラ位置を計算
	position = target + (position_from_target * distance_form_target);

	//座標と注視点、上方向を指定
	DxLib::SetCameraPositionAndTargetAndUpVec(position.ToDXLibVECTOR(), target.ToDXLibVECTOR(), up_vector.ToDXLibVECTOR());

	//視野の最近距離と最遠距離を設定
	DxLib::SetCameraNearFar(vision_near, vision_far);

	//視野角を初期値に
	DxLib::SetupCamera_Perspective(fov * DIGREE_TO_RADIAN);
}

//更新
void Camera::Update()
{
	//移動
	Move();

	//回転
	Rotate();
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
}

//回転
void Camera::Rotate()
{
	//カメラを右スティックor左クリックしながらのマウス動作で回転
	Vec3 input_delta = input->GetLookInput() * sensitivity;

	if (input_delta.LengthSq() != 0.0f)
	{
		yaw_angle += input_delta.x;
		pitch_angle += input_delta.y;
	}

}