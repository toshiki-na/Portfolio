#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
#include "ColliderComponent.h"
#include "NarrowCollisionComputer.h"

//デバッグ用
#include "../../Debug/CollisionDebugView.h"

class CollisionSystem
{
public:
	//コンストラクタ
	CollisionSystem() = default;

	//デストラクタ
	~CollisionSystem() = default;

	//コピー&ムーブ禁止
	CollisionSystem(const CollisionSystem&) = delete;
	CollisionSystem& operator=(const CollisionSystem&) = delete;
	CollisionSystem(CollisionSystem&&) = delete;
	CollisionSystem& operator=(CollisionSystem&&) = delete;

	//衝突判定コンポーネントの登録
	void Register(ColliderComponent* component_);

	//デバッグ描画
	void DebugDraw();

	//更新
	void Update();

private:
	//簡易衝突判定
	void SAPBroadCollision();

	//X軸方向に最小頂点ソート
	void SortCollidersXMinimum();

	//X軸方向の重なり判定
	bool IsOverRapX(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//Y軸方向の重なり判定
	bool IsOverRapY(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//Z軸方向の重なり判定
	bool IsOverRapZ(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//衝突判定
	void NarrowCollision();

private:
	//登録された衝突判定
	std::vector<ColliderComponent*> registered_colliders;

	//衝突判定ペア
	std::vector<std::pair<ColliderComponent*, ColliderComponent*>> narrow_collision_pairs;

	//衝突判定計算機
	NarrowCollisionComputer narrow_collision_computer;

	//衝突判定のデバッグ用
	CollisionDebugView debug_view;
};
#endif