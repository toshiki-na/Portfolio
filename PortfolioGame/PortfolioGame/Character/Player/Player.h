#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "../CharacterBase.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(MovementComponent movement_) :
		CharacterBase(std::move(movement_))
	{
	}
	
	//更新
	void Update() override;

	//描画
	void Draw() override;
};
#endif