#ifndef TRANSFORM_COMPONENT_H
#define TRANSFORM_COMPONENT_H

#include "../../Utility/Vec3.h"

class TransformComponent
{
public:
	//コンストラクタ
	TransformComponent(Vec3 position_ = Vec3::Zero(), Vec3 forward_ = Vec3::Zero(), float yaw_radian_ = 0.0f) :
		position(position_),
		forward(forward_),
		yaw_radian(yaw_radian_)
	{
	}

	//ゲッター
	//位置取得
	const Vec3 GetPosition() const
	{
		return position;
	}

	//前方ベクトル取得
	const Vec3 GetForward() const
	{
		return forward;
	}


	//回転角度取得
	const float GetYawRadian() const
	{
		return yaw_radian;
	}

	//セッター
	//位置変更
	void SetPosition(Vec3 position_)
	{
		position = position_;
	}
	void SetPosition(float x_, float y_, float z_)
	{
		position = Vec3(x_, y_, z_);
	}

	//前方ベクトル変更
	void SetForward(Vec3 new_forward_)
	{
		forward = new_forward_;
	}
	void SetForward(float x_, float y_, float z_)
	{
		forward = Vec3(x_, y_, z_);
	}

	//回転角度変更
	void SetYawRadian(float yaw_radian_)
	{
		yaw_radian = yaw_radian_;
	}

private:
	//位置
	Vec3 position;

	//前方ベクトル
	Vec3 forward;

	//回転角度
	float yaw_radian;
};
#endif