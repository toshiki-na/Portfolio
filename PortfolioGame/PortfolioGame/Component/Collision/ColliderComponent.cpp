#include "ColliderComponent.h"
#include "../../Constant/Tag.h"

//更新
void ColliderComponent::Update()
{
	if (transform != nullptr)
	{
		//衝突判定の位置座標更新
		broad_collider.positon = transform->GetPosition();
		//位置情報は必須のため存在しなければ生成、存在すればそのまま情報更新
		narrow_collider.information[ColliderInformationTag::Position] = transform->GetPosition();
	}
	else
	{
		//衝突判定の位置座標更新
		broad_collider.positon = Vec3::Zero();
		//位置情報は必須のため存在しなければ生成、存在すればそのまま情報更新
		narrow_collider.information[ColliderInformationTag::Position] = Vec3::Zero();

	}
}