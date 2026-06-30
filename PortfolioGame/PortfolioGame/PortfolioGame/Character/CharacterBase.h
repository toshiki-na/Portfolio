#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include <memory>
#include "../Utility/Vec3.h"
#include "../Constant/Tag.h"
#include "ICharacterInput.h"

//コンポーネント
#include "../Component/State/StateComponent.h"
#include "../Component/Transform/TransformComponent.h"
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Collision/ColliderComponent.h"
#include "../Component/Render/RenderComponent.h"
#include "../Component/Animation/AnimatorComponent.h"

class CharacterBase
{
public:
	//コンストラクタ
	CharacterBase(std::unique_ptr<ICharacterInput> input_, StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, ColliderComponent& body_collider_, ColliderComponent& weapon_collider_, AnimatorComponent& animator_, RenderComponent& render_) :
		input(std::move(input_)),
		state(std::move(state_)),
		transform(std::move(transform_)),
		movement(std::move(movement_)),
		animator(std::move(animator_)),
		body_collider(std::move(body_collider_)),
		weapon_collider(std::move(weapon_collider_)),
		render(std::move(render_))
	{
		//各コンポーネントに必要な参照先を設定
		movement.SetComponent(&state, &transform);
		animator.SetStateComponennt(&state);
		render.SetTransformComponent(&transform);
	}

	//生存状態取得
	bool GetActive() const
	{
		return state.IsActive();
	}

	//状態取得
	StateType GetState() const
	{
		return state.GetState();
	}

	//現在HP取得
	int GetHP() const
	{
		return state.GetHP();
	}

	//位置座標コンポーネント取得
	TransformComponent*  GetTransform()
	{
		return &transform;
	}

	//移動コンポーネント取得
	MovementComponent* GetMovement()
	{
		return &movement;
	}

	//身体の衝突判定取得
	ColliderComponent* GetBodyCollider()
	{
		return &body_collider;
	}

	//武器の衝突判定
	ColliderComponent* GetWeaponCollider()
	{
		return &weapon_collider;
	}

	//アニメーションコンポーネント取得
	AnimatorComponent* GetAnimator()
	{
		return &animator;
	}

	//描画コンポーネント取得
	RenderComponent* GetRender()
	{
		return &render;
	}

protected:
	//キャラクターの種類タグ(各キャラクターオブジェクトのコンストラクタで設定)
	CharacterType character_type{ CharacterType::None };

	//入力
	std::unique_ptr<ICharacterInput> input{ nullptr };

	//状態コンポーネント
	StateComponent state;

	//位置座標コンポーネント
	TransformComponent transform;

	//移動コンポーネント
	MovementComponent movement;

	//身体の衝突判定
	ColliderComponent body_collider;

	//武器の衝突判定
	ColliderComponent weapon_collider;

	//アニメーションコンポーネント
	AnimatorComponent animator;
	
	//描画コンポーネント
	RenderComponent render;
};
#endif