#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include "../CharacterBase.h"
#include "../../Constant/Tag.h"

class Player : public CharacterBase
{
public:
	//コンストラクタ
	Player(std::unique_ptr<ICharacterInput> input_, StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, ColliderComponent& body_collider_, ColliderComponent& weapon_collider_, AnimatorComponent& animator_, RenderComponent& render_) :
		CharacterBase(
			std::move(input_),
			state_,
			transform_, 
			movement_, 
			body_collider_,
			weapon_collider_,
			animator_,
			render_
		)
	{
		//キャラクタータイプ設定
		character_type = CharacterType::Player;

		//身体の衝突判定イベント関数セット
		body_collider.SetHitFanction(std::bind(&Player::BodyHitFunction, this, std::placeholders::_1));

		//武器の衝突判定イベント関セット
		weapon_collider.SetHitFanction(std::bind(&Player::WeaponHitFunction, this, std::placeholders::_1));
	}

private:
	//身体の衝突イベント関数
	void BodyHitFunction(ComponentLayer hit_object_layer_);

	//武器の衝突イベント関数
	void WeaponHitFunction(ComponentLayer hit_object_layer_);
};
#endif