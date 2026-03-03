#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <memory>
#include "../../Utility/Vec3.h"
#include "IMoveVectorComputer.h"

class MovementComponent
{
public:
	//コンストラクタ
	MovementComponent(std::unique_ptr<IMoveVectorComputer> move_vec_computer_) :
		move_vec_computer(std::move(move_vec_computer_))
	{
	}

	//デストラクタ
	~MovementComponent() = default;

	//更新
	virtual void Update();

private:
	//位置
	Vec3 position{ Vec3::Zero() };

	//前方ベクトル
	Vec3 forward{ Vec3::Zero() };

	//回転角度
	float yaw_angle{ 0.0f };

	//移動速度(/s)
	float speed{ 0.0f };

	//移動方向入力
	std::unique_ptr<IMoveVectorComputer> move_vec_computer;
};
#endif