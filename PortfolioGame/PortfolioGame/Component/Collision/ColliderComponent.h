#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include "../../Constant/Tag.h"
#include "../../Component/Transform/TransformComponent.h"
#include "Broad/BroadCollider.h"
#include "Narrow/NarrowCollider.h"

class ColliderComponent
{
public:
	//コンストラクタ
	ColliderComponent(BroadCollider broad_collider_, NarrowCollider narrow_collider_):
		broad_collider(broad_collider_),
		narrow_collider(narrow_collider_)
	{
	}

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_);

	//簡易衝突判定の取得
	BroadCollider* GetNarrowCollider()
	{
		return &broad_collider;
	}

	//衝突判定の取得
	NarrowCollider* GetBroadCollider()
	{
		return &narrow_collider;
	}

	//更新
	void Update();

private:
	//位置情報
	TransformComponent* transform{ nullptr };

	//簡易衝突判定
	BroadCollider broad_collider;

	//衝突判定
	NarrowCollider narrow_collider;
};
#endif