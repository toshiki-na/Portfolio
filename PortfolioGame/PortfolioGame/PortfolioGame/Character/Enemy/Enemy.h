#ifndef ENEMY_H
#define ENEMY_H

#include <memory>
#include "../CharacterBase.h"
#include "../../Constant/Tag.h"

class Enemy : public CharacterBase
{
public:
	//コンストラクタ
	Enemy(StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, ColliderComponent& body_collider_, ColliderComponent& weapon_collider_, AnimatorComponent& animator_, RenderComponent& render_) :
		CharacterBase(
			nullptr,
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
		character_type = CharacterType::Enemy;

		//初期は非生存状態で生成
		state.SetActive(false);

		//身体の衝突判定イベント関数セット
		body_collider.SetHitFanction(std::bind(&Enemy::BodyHitFunction, this, std::placeholders::_1));

		//武器の衝突判定イベント関セット
		weapon_collider.SetHitFanction(std::bind(&Enemy::WeaponHitFunction, this, std::placeholders::_1));
	}

private:
	//身体の衝突イベント関数
	void BodyHitFunction(ComponentLayer hit_object_layer_);

	//武器の衝突イベント関数
	void WeaponHitFunction(ComponentLayer hit_object_layer_);
};
#endif