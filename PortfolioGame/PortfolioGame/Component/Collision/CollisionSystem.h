#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
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

	//簡易衝突判定の登録
	void BroadRegister(BroadCollider* broad_collider_, ComponentLayer layer_);

	//衝突判定の登録
	void NarrowRegister(NarrowCollider* narrow_collider_, ComponentLayer layer_);

	//更新
	void Update();

private:

private:


};
#endif