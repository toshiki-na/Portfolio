#ifndef ENEMY_MOVEMENT_COMPUTER_H
#define ENEMY_MOVEMENT_COMPUTER_H

#include <memory>
#include "../../../Utility/Vec3.h"
#include "../IMovementComputer.h"
#include "../../../Component/State/StateComponent.h"
#include "../../../Component/Transform/TransformComponent.h"

class EnemyMovementComputer : public IMovementComputer
{
public:
	//コンストラクタ
	EnemyMovementComputer(float speed_, Vec3* player_position = nullptr) :
		speed(speed_),
		player_position(player_position)
	{
	}

	//状態コンポーネント参照先の設定
	void SetStateComponent(StateComponent* state_) override
	{
		state = state_;
	}

	//位置コンポーネント参照先の設定
	void SetTransformComponent(TransformComponent* transform_) override
	{
		transform = transform_;
	}


	//入力アクションの実行
	void InputAction() override;

	//移動の実行
	void Move() override;

private:
	//移動方向の計算
	Vec3 CalculateMoveVec();

private:
	//状態
	StateComponent* state{ nullptr };

	//位置情報
	TransformComponent* transform{ nullptr };

	//移動速度(/s)
	float speed{ 0.0f };

	//プレイヤーの位置情報
	Vec3* player_position;
};
#endif