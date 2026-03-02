#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include "../Utility/Vec3.h"

class MovementComponent
{
public:
	//コンストラクタ
	MovementComponent() = default;

	//デストラクタ
	~MovementComponent() = default;

	//更新
	virtual void Update() = 0;

private:
	//位置
	Vec3 position{ Vec3::Zero() };

	//前方ベクトル
	Vec3 forward{ Vec3::Zero() };

	//回転角度
	float yaw_angle{ 0.0f };

	//移動速度(/s)
	float speed{ 0.0f };
};
#endif