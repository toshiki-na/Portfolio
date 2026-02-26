#ifndef PLAYER_H
#define PLAYER_H

#include "../CharacterBase.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(float x, float y, float z) :
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