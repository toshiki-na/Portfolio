#ifndef MOVEMENT_COMPONENT_H
#define MOVEMENT_COMPONENT_H

#include <memory>
#include "../../Constant/Tag.h"
#include "IMovementComputer.h"
#include "../State/StateComponent.h"
#include "../Transform/TransformComponent.h"

class MovementComponent
{
public:
	//コンストラクタ
	MovementComponent(ComponentLayer layer_, std::unique_ptr<IMovementComputer> movement_computer_) :
		layer(layer_),
		movement_computer(std::move(movement_computer_))
	{
	}

	//動態計算機に必要なコンポーネントの設定
	void SetComponent(StateComponent* state_, TransformComponent* transform_)
	{
		movement_computer->SetStateComponent(state_);
		movement_computer->SetTransformComponent(transform_);
	}

	//コンポーネントレイヤー取得
	ComponentLayer GetLayer() const
	{
		return layer;
	}

	//更新
	void Update();

private:
	//コンポーネントレイヤー
	ComponentLayer layer;

	//動態計算機
	std::unique_ptr<IMovementComputer> movement_computer;
};
#endif