#ifndef INTERFACE_MOVE_VECTOR_COMPUTER_H
#define INTERFACE_MOVE_VECTOR_COMPUTER_H

#include "../../Utility/Vec3.h"
#include "../State/StateComponent.h"
#include "../Transform/TransformComponent.h"

class IMovementComputer
{
public:
	//デストラクタ
	virtual ~IMovementComputer() = default;

	//状態コンポーネント参照先の設定
	virtual void SetStateComponent(StateComponent* state_) = 0;

	//位置コンポーネント参照先の設定
	virtual void SetTransformComponent(TransformComponent* transform_) = 0;

	//入力アクションの実行
	virtual void InputAction() = 0;

	//移動の実行
	virtual void Move() = 0;
};
#endif