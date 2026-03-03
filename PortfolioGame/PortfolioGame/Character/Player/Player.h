#ifndef PLAYER_H
#define PLAYER_H

#include "../CharacterBase.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player() :
	{
	}

	//デストラクタ
	~Player() = default;
	
	//更新
	void Update() override;

	//描画
	void Draw() override;

private:

};
#endif