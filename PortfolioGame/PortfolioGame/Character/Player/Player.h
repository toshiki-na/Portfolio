#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "../CharacterBase.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(TransformComponent& transform_, MovementComponent& movement_, RenderComponent& render_) :
		CharacterBase(
			transform_, 
			movement_, 
			render_
		)
	{
	}
};
#endif