#include "ColliderComponent.h"
#include "../../Constant/Tag.h"

//更新
void ColliderComponent::Update()
{
	//衝突判定の更新
	UpdateNarrowCollider();

	//簡易衝突判定の更新
	UpdateBroadCollider();
}

//衝突処理
void ColliderComponent::ReceveHit(ComponentLayer layer_)
{
	hit_function(layer_);
}

//簡易衝突判定の最小頂点と最大頂点座標計算
void ColliderComponent::CalculateBroadVertex(Vec3& min_result_, Vec3& max_result_)
{
	switch (narrow_collider->shape)
	{
		//線分
	case ColliderShapeTag::Ray:
		Vec3 start = narrow_collider->start;
		Vec3 end = narrow_collider->end;
		min_result_ =
		{
			min(start.x, end.x),
			min(start.y, end.y),
			min(start.z, end.z),
		};
		max_result_ =
		{
			max(start.x, end.x),
			max(start.y, end.y),
			max(start.z, end.z),

		};
		break;

		//球
	case ColliderShapeTag::Sphere:
		float radius = narrow_collider->radius;
		Vec3 position = narrow_collider->position;
		min_result_ =
		{
			position.x - radius,
			position.y - radius,
			position.z - radius,
		};
		max_result_ =
		{
			position.x + radius,
			position.y + radius,
			position.z + radius,
		};
		break;

		//OBB
	case ColliderShapeTag::Box:
		Vec3 position = narrow_collider->position;
		float half_scale_length = narrow_collider->half_scale.Length();
		min_result_ =
		{
			position.x - half_scale_length,
			position.y - half_scale_length,
			position.z - half_scale_length,
		};
		max_result_ =
		{
			position.x + half_scale_length,
			position.y + half_scale_length,
			position.z + half_scale_length,
		};
		break;

	defatult:
		min_result_ = Vec3::Zero();
		max_result_ = Vec3::Zero();
		break;
	}

}

//簡易衝突判定の生成
std::unique_ptr<BroadCollider> ColliderComponent::CreateBroadCollider()
{
	//最小頂点と最大頂点計算
	Vec3 min_vertex = Vec3::Zero();
	Vec3 max_vertex = Vec3::Zero();

	CalculateBroadVertex(min_vertex, max_vertex);

	broad_collider = std::make_unique<BroadCollider>(min_vertex, max_vertex);
}

//簡易衝突判定の情報更新
void ColliderComponent::UpdateBroadCollider()
{
	//位置情報が不明なコンポーネントなので0座標に固定しておく
	if (transform == nullptr)
	{
		broad_collider->min_vertex = Vec3::Zero();
		broad_collider->max_vertex = Vec3::Zero();
	}

	//最小頂点と最大頂点計算
	CalculateBroadVertex(broad_collider->min_vertex, broad_collider->max_vertex);
}

//衝突判定の情報更新
void ColliderComponent::UpdateNarrowCollider()
{
	//位置情報が不明なコンポーネントなので0座標に固定しておく
	if (transform == nullptr)
	{
		narrow_collider->position = Vec3::Zero();
	}

	//位置情報更新
	narrow_collider->position = transform->GetPosition();
}