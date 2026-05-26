#ifndef COLLISION_SYSTEM_H
#define COLLISION_SYSTEM_H

#include <vector>
#include "ColliderComponent.h"
#include "SweepAndPrune/SAPBuffer.h"

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

	//更新
	void Update();

private:
	//簡易衝突判定
	void SAPBroadCollision();

	//YZ軸方向のAABB衝突判定
	bool CheackYZAABBCollision(SAPBuffer sap_01_, SAPBuffer sap_02_);

	//衝突判定
	void NarrowCollision();

	//線分と線分の衝突判定
	void CheackCollisionRayAndRay(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//球と球の衝突判定
	void CheackCollisionSphereAndSphere(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//OBBとOBBの衝突判定
	void CheackCollisionOBBAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//線分と球の衝突判定
	void CheackCollisionRayAndSphere(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//線分とOBBの衝突判定
	void CheackCollisionRayAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

	//球とOBBの衝突判定
	void CheackCollisionSphereAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_);

private:
	//登録された衝突判定
	std::vector<SAPBuffer> registered_colliders;

	//衝突判定ペア
	std::vector<std::pair<ColliderComponent*, ColliderComponent*>> narrow_collision_pairs;
};
#endif