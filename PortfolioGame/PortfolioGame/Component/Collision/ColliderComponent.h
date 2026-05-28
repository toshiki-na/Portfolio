#ifndef COLLIDER_COMPONENT_H
#define COLLIDER_COMPONENT_H

#include <memory>
#include <functional>
#include "../../Constant/Tag.h"
#include "../../Component/Transform/TransformComponent.h"
#include "Broad/BroadCollider.h"
#include "Narrow/NarrowCollider.h"

class ColliderComponent
{
public:
	//コンストラクタ
	ColliderComponent(std::unique_ptr<BroadCollider> broad_collider_, std::unique_ptr<NarrowCollider> narrow_collider_, std::function<void(ComponentLayer, int)> hit_function_, ComponentLayer layer_) :
		broad_collider(std::move(broad_collider_)),
		narrow_collider(std::move(narrow_collider_)),
		hit_function(hit_function_),
		layer(layer_)
	{
	};

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_)
	{
		transform = transform_;
	}

	//コンポーネントレイヤー取得
	ComponentLayer GetLayer() const
	{
		return layer;
	}

	//簡易衝突判定の取得
	BroadCollider& GetBroadCollider()
	{
		return *broad_collider;
	}

	//衝突判定の取得
	NarrowCollider& GetNarrowCollider()
	{
		return *narrow_collider;
	}

	//更新
	void Update();

private:
	//コンポーネントレイヤー
	ComponentLayer layer;

	//位置情報
	TransformComponent* transform{ nullptr };

	//簡易衝突判定
	std::unique_ptr<BroadCollider> broad_collider;

	//衝突判定
	std::unique_ptr<NarrowCollider> narrow_collider;

	//衝突時のイベント関数
	std::function<void(ComponentLayer, int)> hit_function{ nullptr };
};
#endif