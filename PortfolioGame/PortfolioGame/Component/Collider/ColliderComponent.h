#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include "../../Constant/Tag.h"
#include "../../Component/Transform/TransformComponent.h"
#include "Narrow/NarrowCollider.h"
#include "Broad/BroadCollider.h"

class ColliderComponent
{
public:
	//コンストラクタ
	ColliderComponent() = default;

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_);

	//簡易衝突判定の取得
	NarrowCollider* GetNarrowCollider()
	{
		return &narrow_collider;
	}

	//更新
	void Update();

private:
	//位置情報
	TransformComponent* transform{ nullptr };

	//簡易衝突判定
	NarrowCollider narrow_collider;

	//衝突判定
	BroadCollider broad_collider;
};
#endif