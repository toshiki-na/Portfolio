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
	ColliderComponent(std::unique_ptr<NarrowCollider> narrow_collider_, ComponentLayer layer_) :
		narrow_collider(std::move(narrow_collider_)),
		layer(layer_)
	{
		//簡易衝突判定生成
		broad_collider = std::move(CreateBroadCollider());
	};

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_)
	{
		transform = transform_;
	}

	//衝突イベント関数セット
	void SetHitFanction(std::function<void(ComponentLayer)> hit_function_)
	{
		hit_function = hit_function_;
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

	//衝突処理
	void ReceveHit(ComponentLayer layer_);

	//更新
	void Update();

private:
	//簡易衝突判定の最小頂点と最大頂点座標計算
	void CalculateBroadVertex(Vec3& min_result_, Vec3& max_result_);

	//簡易衝突判定の生成
	std::unique_ptr<BroadCollider> CreateBroadCollider();

	//簡易衝突判定の情報更新
	void UpdateBroadCollider();

	//衝突判定の情報更新
	void UpdateNarrowCollider();

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
	std::function<void(ComponentLayer)> hit_function{ nullptr };
};
#endif