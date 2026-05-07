#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <memory>
#include "../../Constant/Tag.h"
#include "../../Component/Transform/TransformComponent.h"
#include "Broad/BroadCollider.h"
#include "Narrow/NarrowCollider.h"

class ColliderComponent
{
public:
	//コンストラクタ
	ColliderComponent(std::unique_ptr<BroadCollider> broad_collider_, std::unique_ptr<NarrowCollider> narrow_collider_) :
		broad_collider(std::move(broad_collider_)),
		narrow_collider(std::move(narrow_collider_))
	{
	};

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_);

	//簡易衝突判定の取得
	BroadCollider& GetNarrowCollider()
	{
		return *broad_collider;
	}

	//衝突判定の取得
	NarrowCollider& GetBroadCollider()
	{
		return *narrow_collider;
	}

	//更新
	void Update();

private:
	//位置情報
	TransformComponent* transform{ nullptr };

	//簡易衝突判定
	std::unique_ptr<BroadCollider> broad_collider;

	//衝突判定
	std::unique_ptr<NarrowCollider> narrow_collider;
};
#endif