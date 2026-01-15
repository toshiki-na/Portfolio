#ifndef PLAYER_H
#define PLAYER_H

#include "../ObjectBase.h"

class Player : public ObjectBase
{
public:
	//コンストラクタ
	Player(float x, float y, float z) :
		ObjectBase(Vec3{x, y, z})
	{
	}

	//デストラクタ
	~Player() = default;
	
	//更新
	void Update();

	//描画
	void Draw();

private:
};
#endif