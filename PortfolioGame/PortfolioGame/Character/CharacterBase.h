#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include <memory>
#include "../Utility/Vec3.h"
#include "../Constant/Tag.h"
#include "ICharacterInput.h"
#include "../Component/State/StateComponent.h"
#include "../Component/Transform/TransformComponent.h"
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Render/RenderComponent.h"
#include "../Component/Animation/AnimatorComponent.h"

class CharacterBase
{
public:
	//コンストラクタ
	CharacterBase(std::unique_ptr<ICharacterInput> input_, StateComponent& state_, TransformComponent& transform_, MovementComponent& movement_, AnimatorComponent& animator_, RenderComponent& render_) :
		input(std::move(input_)),
		state(std::move(state_)),
		transform(std::move(transform_)),
		movement(std::move(movement_)),
		animator(std::move(animator_)),
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

	//アニメーションコンポーネント
	AnimatorComponent animator;
	
	//描画コンポーネント
	RenderComponent render;
};
#endif