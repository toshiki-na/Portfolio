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
	CharacterBase(TransformComponent transform_, MovementComponent movement_, RenderComponent render_) :
		transform(std::move(transform_)),
		movement(std::move(movement_)),
		render(std::move(render_))
	{
	}

	//更新
	virtual void Update() = 0;

	//描画
	virtual void Draw() = 0;

	//生存状態取得
	bool GetActive() const
	{
		return active;
	}

protected:
	//生存フラグ
	bool active{ true };

	//位置座標コンポーネント
	TransformComponent transform;

	//移動コンポーネント
	MovementComponent movement;

	//描画コンポーネント
	RenderComponent render;
};
#endif