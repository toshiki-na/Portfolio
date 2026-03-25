#include "MovementSystem.h"

//移動コンポーネントの登録
void MovementSystem::Register(MovementComponent* component_, ComponentLayer layer_)
{
	switch (layer_)
	{
		//プレイヤー
	case ComponentLayer::Player:
		player_movement = component_;
		break;

		//敵
	case ComponentLayer::Enemy:
		enemy_movements.push_back(component_);
		break;

	default:
		break;
	}
}

//更新
void MovementSystem::Update()
{
	//プレイヤー更新
	player_movement->Update();

	//敵の更新
	for (auto& EnemyMovement : enemy_movements)
	{
		EnemyMovement->Update();
	}

	//更新が終わったら登録された移動コンポーネントリセット
	player_movement = nullptr;
	enemy_movements.clear();
}