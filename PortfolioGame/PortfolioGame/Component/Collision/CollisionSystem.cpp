#include "CollisionSystem.h"

//簡易衝突判定の登録
void CollisionSystem::Register(ColliderComponent* component_, ComponentLayer layer_)
{
	switch (layer_)
	{
		//プレイヤー
	case ComponentLayer::Player:
		player_collider = component_;
		break;

		//敵
	case ComponentLayer::Enemy:
		enemy_colliders.push_back(component_);
		break;

		//武器
	case ComponentLayer::Weapon:
		weapon_collider = component_;
		break;

		//例外
	default:
		break;
	}
}

//更新
void CollisionSystem::Update()
{

}

//簡易衝突判定
bool CollisionSystem::BroadCollision(BroadCollider* collider_01_, BroadCollider* collider_02_)
{
	//2つの簡易衝突判定のx,y,z最小点(左下手前点)と最大点(右上奥点)を算出
	Vec3 collider_01_min = collider_01_->positon - collider_01_->scale;
	Vec3 collider_01_max = collider_01_->positon + collider_01_->scale;

	Vec3 collider_02_min = collider_02_->positon - collider_02_->scale;
	Vec3 collider_02_max = collider_02_->positon + collider_02_->scale;

	//各軸方向に対して明らかに離れている時はfalseを返す
	//x軸方向
	if (collider_01_max.x < collider_02_min.x || collider_02_max.x < collider_01_min.x)
	{
		return false;
	}

	//y軸方向
	if (collider_01_max.y < collider_02_min.y || collider_02_max.y < collider_01_min.y)
	{
		return false;
	}

	//z軸方向
	if (collider_01_max.z < collider_02_min.z || collider_02_max.z < collider_01_min.z)
	{
		return false;
	}

	//すべて重なりが存在しているので簡易衝突判定では衝突している
	return true;
}

//衝突判定
bool CollisionSystem::NarrowCollision(NarrowCollider* collider_01_, NarrowCollider* collider_02_)
{
}
