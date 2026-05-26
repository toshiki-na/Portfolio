#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "../CharacterBase.h"
#include "../../Constant/Tag.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(std::unique_ptr<ICharacterInput> input_, StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, AnimatorComponent& animator_, RenderComponent& render_) :
		CharacterBase(
			std::move(input_),
			state_,
			transform_, 
			movement_, 
			animator_,
			render_
		)
	{
		//キャラクタータイプ設定
		character_type = CharacterType::Player;
	}
};
#endif