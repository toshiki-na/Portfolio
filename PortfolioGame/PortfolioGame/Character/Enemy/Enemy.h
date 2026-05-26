#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include "../CharacterBase.h"
#include "../../Constant/Tag.h"

class Enemy : public CharacterBase
{
public:
	//コンストラクタ
	Enemy(StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, AnimatorComponent& animator_, RenderComponent& render_) :
		CharacterBase(
			nullptr,
			state_,
			transform_,
			movement_,
			animator_,
			render_
		)
	{
		//キャラクタータイプ設定
		character_type = CharacterType::Enemy;
	}
};
#endif