#ifndef MOVEMENT_SYSTEM_H
#define MOVEMENT_SYSTEM_H

#include <vector>
#include "../../Component/Movement/MovementComponent.h"
#include "../../Constant/Tag.h"

class MovementSystem
{
public:
	//コンストラクタ
	MovementSystem() = default;

	//移動コンポーネントの登録
	void Register(MovementComponent* component_, ComponentLayer layer_);

	//更新
	void Update();

private:
	//登録された移動コンポーネント
	//プレイヤー
	MovementComponent* player_movement;

	//敵
	std::vector<MovementComponent*> enemy_movement;	
};
#endif