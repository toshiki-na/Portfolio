#ifndef PLAYER_H
#define PLAYER_H

#include "../CharacterBase.h"
#include "../../Component/MovementComponent.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(MovementComponent movement_) :
		CharacterBase(movement_)
	{
	}

	//デストラクタ
	~Player() = default;
	
	//更新
	void Update() override;

	//描画
	void Draw() override;

private:
	//移動
	void Move();

private:
	//移動速度(/s)
	float speed{ 10.0f };
};
#endif