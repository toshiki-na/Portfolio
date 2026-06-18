#include "ColliderComponent.h"
#include "../../Constant/Tag.h"

//更新
void ColliderComponent::Update()
{
	//位置情報の存在確認
	if (transform != nullptr)
	{
		//簡易衝突判定の情報更新
		broad_collider->positon = transform->GetPosition();
		broad_collider->positon.y += broad_collider->scale.y / 2.0f;

		//衝突判定の情報更新
		narrow_collider->position = transform->GetPosition();
	}
	else
	{
		//位置情報が不明なコンポーネントなので0座標に固定しておく
		broad_collider->positon = Vec3::Zero();
		narrow_collider->position = Vec3::Zero();
	}
}

//衝突処理
void ColliderComponent::ReceveHit(ComponentLayer layer_)
{
	hit_function(layer_);
}