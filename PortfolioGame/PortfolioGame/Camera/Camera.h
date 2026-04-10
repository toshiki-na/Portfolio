#ifndef CAMERA_H
#define CAMERA_H

#include <memory>
#include "../Constant/ConstantValue.h"
#include "../Utility/Vec3.h"
#include "CameraInput/ICameraInput.h"
#include "../Component/Transform/TransformComponent.h"

class Camera
{
public:
	//コンストラクタ
	Camera(std::unique_ptr<ICameraInput> input_) :
		input(std::move(input_))
	{
	}

public:
	//初期化
	void Initialize(TransformComponent* target_);

	//更新
	void Update();

	//視野角変更
	void ChangeFoV(float new_fov_);

	//操作入力切り替え
	void ChangeInput(std::unique_ptr<ICameraInput> new_input_);

private:
	//移動
	void Move();

	//回転
	void Rotate();

private:
	//位置
	Vec3 position{ Vec3::Zero() };

	//注視点
	TransformComponent* target{ nullptr };

	//注視点からカメラ位置までのベクトル
	Vec3 position_from_target{ 0.0f, 0.0f, -1.0f };

	//注視点からカメラ位置までの距離
	float distance_form_target{ 500.0f };

	//垂直方向の回転角度
	float yaw_angle{ 0.0f };

	//水平方向の回転角度
	float pitch_angle{ 0.0f };

	//視野角
	float fov{ 60.0f };

	//視点感度
	float sensitivity{ 0.01f };

	//カメラ操作入力
	std::unique_ptr<ICameraInput> input;
};
#endif