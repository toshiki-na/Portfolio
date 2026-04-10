#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include <memory>
#include "../Utility/Vec3.h"
#include "../Component/Transform/TransformComponent.h"
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Render/RenderComponent.h"

class CharacterBase
{
public:
	//コンストラクタ
	CharacterBase(TransformComponent& transform_, MovementComponent& movement_, RenderComponent& render_) :
		transform(std::move(transform_)),
		movement(std::move(movement_)),
		render(std::move(render_))
	{
		//位置情報参照先セット
		movement.SetTransformComponent(&transform);
		render.SetTransformComponent(&transform);
	}

	//生存状態取得
	bool GetActive() const
	{
		return active;
	}

	//現在HP取得
	int GetHP() const
	{
		return hp;
	}

	//位置座標コンポーネント取得
	TransformComponent* GetTransform()
	{
		return &transform;
	}

	//移動コンポーネント取得
	MovementComponent* GetMovement()
	{
		return &movement;
	}

	//描画コンポーネント取得
	RenderComponent* GetRender()
	{
		return &render;
	}

protected:
	//生存フラグ
	bool active{ true };

	//HP
	int hp{ 100 };

	//位置座標コンポーネント
	TransformComponent transform;

	//移動コンポーネント
	MovementComponent movement;

	//描画コンポーネント
	RenderComponent render;
};
#endif