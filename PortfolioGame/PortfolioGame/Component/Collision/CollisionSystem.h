#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
#include "ColliderComponent.h"
#include "Broad/BroadCollider.h"
#include "Narrow/NarrowCollider.h"

class CollisionSystem
{
public:
	//コンストラクタ
	CollisionSystem() = default;

	//デストラクタ
	CollisionSystem() = default;

	//コピー&ムーブ禁止
	CollisionSystem(const CollisionSystem&) = delete;
	CollisionSystem& operator=(const CollisionSystem&) = delete;
	CollisionSystem(CollisionSystem&&) = delete;
	CollisionSystem& operator=(CollisionSystem&&) = delete;

	//衝突判定コンポーネントの登録
	void Register(ColliderComponent* component_, ComponentLayer layer_);

	//更新
	void Update();

private:
	//簡易衝突判定
	bool BroadCollision(BroadCollider* collider_01_, BroadCollider* collider_02_);

	//衝突判定
	bool NarrowCollision(NarrowCollider* collider_01_, NarrowCollider* collider_02_);

private:
	//プレイヤー衝突判定コンポーネント
	ColliderComponent* player_collider{ nullptr };

	//武器衝突判定コンポーネント
	ColliderComponent* weapon_collider{ nullptr };

	//敵衝突判定コンポーネント
	std::vector<ColliderComponent*> enemy_colliders;
};
#endif