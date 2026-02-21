#ifndef PLAYER_H
#define PLAYER_H

#include "../ObjectBase.h"

class Player : public ObjectBase
{
public:
	//コンストラクタ
	Player(float x, float y, float z) :
		ObjectBase(Vec3{ x, y, z }, Vec3{0.0f, 0.0f, -1.0f})
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
	float speed{ 0.0f };
};
#endif