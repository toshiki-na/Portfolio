#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <memory>
#include "IMoveVectorComputer.h"
#include "../Transform/TransformComponent.h"

class MovementComponent
{
public:
	//コンストラクタ
	MovementComponent(TransformComponent& transform_, std::unique_ptr<IMoveVectorComputer> move_vec_computer_) :
		transform(transform_),
		move_vec_computer(std::move(move_vec_computer_))
	{
	}

	//更新
	void Update();

private:
	//位置情報
	TransformComponent& transform;

	//移動速度(/s)
	float speed{ 0.0f };

	//移動方向計算機
	std::unique_ptr<IMoveVectorComputer> move_vec_computer;
};
#endif