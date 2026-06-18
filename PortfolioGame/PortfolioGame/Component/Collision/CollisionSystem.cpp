#include "CollisionSystem.h"
#include <vector>
#include <algorithm>
#include "SweepAndPrune/SAPBuffer.h"

//簡易衝突判定の登録
void CollisionSystem::Register(ColliderComponent* component_)
{
	SAPBuffer sap_buffer(component_);
	registered_colliders.push_back(sap_buffer);
}

//更新
void CollisionSystem::Update()
{
	//簡易衝突判定
	SAPBroadCollision();

	//衝突判定
	NarrowCollision();
}

//簡易衝突判定
void CollisionSystem::SAPBroadCollision()
{
	//SweepAndPrune衝突判定
	//x軸最小頂点をソート
	SortCollidersXMinimum();

	for (int i = 0; i < registered_colliders.size() - 1; ++i)
	{
		for (int j = i; j < registered_colliders.size(); ++j)
		{
			//X軸の最大、最小頂点間に最小頂点があるオブジェクトとは当たってる可能性あり
			if (registered_colliders[j].min_vertex.x <= registered_colliders[i].max_vertex.x)
			{
				//Y軸、Z軸方向のAABB衝突判定
				if (CheackYZAABBCollision(registered_colliders[i], registered_colliders[j]))
				{
					//簡易衝突判定で衝突しているので厳密な衝突判定用ペアに登録
					narrow_collision_pairs.push_back({ registered_colliders[i].component, registered_colliders[j].component });
				}
			}
			//ソート済みのため以降はすべて衝突の可能性がないので判定終了
			else
			{
				break;
			}
		}
	}

}

//X軸最小頂点をソート
void CollisionSystem::SortCollidersXMinimum()
{
	std::sort(
		registered_colliders.begin(), 
		registered_colliders.end(),
		[](SAPBuffer buffer_01, SAPBuffer buffer_02)
		{
			return buffer_01.min_vertex.x < buffer_02.min_vertex.x;
		}
	);
}

//YZ軸方向のAABB衝突判定
bool CollisionSystem::CheackYZAABBCollision(SAPBuffer sap_01_, SAPBuffer sap_02_)
{
	//Z軸方向の判定
	if (sap_01_.max_vertex.z < sap_02_.min_vertex.z || sap_02_.max_vertex.z < sap_01_.min_vertex.z)
	{
		return false;
	}

	//Y軸方向の判定
	if (sap_01_.max_vertex.y < sap_02_.min_vertex.y || sap_02_.max_vertex.y < sap_01_.min_vertex.y)
	{
		return false;
	}

	return true;
}

//衝突判定
void CollisionSystem::NarrowCollision()
{
	for (auto& NarrowCollisionPair : narrow_collision_pairs)
	{
		NarrowCollider narrow_collider_01 = NarrowCollisionPair.first->GetNarrowCollider();
		NarrowCollider narrow_collider_02 = NarrowCollisionPair.second->GetNarrowCollider();

		ColliderShapeTag collider_01_shape = narrow_collider_01.shape;
		ColliderShapeTag collider_02_shape = narrow_collider_02.shape;

		//線分と線分の衝突判定
		if (collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Ray)
		{
			if (narrow_collision_computer.CheackCollisionRayAndRay(narrow_collider_01, narrow_collider_02))
			{
				//衝突通知
				NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
				NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
			}
		}

		//球と球の衝突判定
		if (collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Sphere)
		{
			if (narrow_collision_computer.CheackCollisionSphereAndSphere(narrow_collider_01, narrow_collider_02))
			{
				//衝突通知
				NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
				NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
			}
		}

		//OBBとOBBの衝突判定
		if (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Box)
		{
			narrow_collision_computer.CheackCollisionOBBAndOBB(narrow_collider_01, narrow_collider_02);
		}

		//線分と球の衝突判定
		if ((collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Sphere) || (collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Ray))
		{
			if (collider_01_shape == ColliderShapeTag::Ray)
			{
				if (narrow_collision_computer.CheackCollisionRayAndSphere(narrow_collider_01, narrow_collider_02))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
			else
			{
				if (narrow_collision_computer.CheackCollisionRayAndSphere(narrow_collider_02, narrow_collider_01))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
		}

		//線分とOBBの衝突判定
		if ((collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Box) || (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Ray))
		{
			if (collider_01_shape == ColliderShapeTag::Ray)
			{
				if (narrow_collision_computer.CheackCollisionRayAndOBB(narrow_collider_01, narrow_collider_02))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
			else
			{
				if (narrow_collision_computer.CheackCollisionRayAndOBB(narrow_collider_02, narrow_collider_01))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
		}

		//球とOBBの衝突判定
		if ((collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Box) || (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Sphere))
		{
			if (collider_01_shape == ColliderShapeTag::Sphere)
			{
				if (narrow_collision_computer.CheackCollisionSphereAndOBB(narrow_collider_01, narrow_collider_02))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
			else
			{
				if (narrow_collision_computer.CheackCollisionSphereAndOBB(narrow_collider_02, narrow_collider_01))
				{
					//衝突通知
					NarrowCollisionPair.first->ReceveHit(NarrowCollisionPair.second->GetLayer());
					NarrowCollisionPair.second->ReceveHit(NarrowCollisionPair.first->GetLayer());
				}
			}
		}
	}
}