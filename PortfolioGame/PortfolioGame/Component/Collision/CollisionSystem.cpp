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
	std::sort(registered_colliders.begin(), registered_colliders.end(),
		[](SAPBuffer buffer_01, SAPBuffer buffer_02)
		{
			return buffer_01.min_vertex.x < buffer_02.min_vertex.x;
		}
	);

	//最小頂点のxが小さい順でソート済みなので配列の前の簡易衝突判定の最大頂点のxよりも最小頂点のxが小さい簡易衝突判定はx軸方向で交差しているので衝突している可能性がある
	for (int i = 0; i < registered_colliders.size() - 1; i++)
	{
		for (int j = 1; j < registered_colliders.size(); j++)
		{
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
		ColliderComponent* collider_01 = NarrowCollisionPair.first;
		ColliderComponent* collider_02 = NarrowCollisionPair.second;

		ColliderShapeTag collider_01_shape = collider_01->GetNarrowCollider().shape;
		ColliderShapeTag collider_02_shape = collider_02->GetNarrowCollider().shape;

		//線分と線分の衝突判定
		if (collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Ray)
		{
			CheackCollisionRayAndRay(collider_01, collider_02);
		}

		//球と球の衝突判定
		if (collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Sphere)
		{
			CheackCollisionSphereAndSphere(collider_01, collider_02);
		}

		//OBBとOBBの衝突判定
		if (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Box)
		{
			CheackCollisionOBBAndOBB(collider_01, collider_02);
		}

		//線分と球の衝突判定
		if ((collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Sphere) || (collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Ray))
		{
			if (collider_01_shape == ColliderShapeTag::Ray)
			{
				CheackCollisionRayAndSphere(collider_01, collider_02);
			}
			else
			{
				CheackCollisionRayAndSphere(collider_02, collider_01);
			}
		}

		//線分とOBBの衝突判定
		if ((collider_01_shape == ColliderShapeTag::Ray && collider_02_shape == ColliderShapeTag::Box) || (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Ray))
		{
			if (collider_01_shape == ColliderShapeTag::Ray)
			{
				CheackCollisionRayAndOBB(collider_01, collider_02);
			}
			else
			{
				CheackCollisionRayAndOBB(collider_02, collider_01);
			}
		}

		//球とOBBの衝突判定
		if ((collider_01_shape == ColliderShapeTag::Sphere && collider_02_shape == ColliderShapeTag::Box) || (collider_01_shape == ColliderShapeTag::Box && collider_02_shape == ColliderShapeTag::Sphere))
		{
			if (collider_01_shape == ColliderShapeTag::Sphere)
			{
				CheackCollisionSphereAndOBB(collider_01, collider_02);
			}
			else
			{
				CheackCollisionSphereAndOBB(collider_02, collider_01);
			}
		}
	}
}

//線分と線分の衝突判定
void CollisionSystem::CheackCollisionRayAndRay(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Ray || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Ray)
	{
		//形状不一致で衝突判定終了
		return;
	}
}

//球と球の衝突判定
void CollisionSystem::CheackCollisionSphereAndSphere(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Sphere || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return;
	}

	//衝突判定情報から距離と半径の2乗を取得
	NarrowCollider narrow_collider_01 = collider_01_->GetNarrowCollider();
	NarrowCollider narrow_collider_02 = collider_02_->GetNarrowCollider();
	float distance_sq = (narrow_collider_01.information[ColliderInformationTag::Position] - narrow_collider_02.information[ColliderInformationTag::Position]).LengthSq();
	float total_radius_sq = (narrow_collider_01.information[ColliderInformationTag::Radius] - narrow_collider_02.information[ColliderInformationTag::Radius]).LengthSq();

	//衝突判定
	if (distance_sq <= total_radius_sq)
	{
		//衝突している
	}
}

//OBBとOBBの衝突判定
void CollisionSystem::CheackCollisionOBBAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{	
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Box || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return;
	}
}

//線分と球の衝突判定
void CollisionSystem::CheackCollisionRayAndSphere(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Ray || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return;
	}
}

//線分とOBBの衝突判定
void CollisionSystem::CheackCollisionRayAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{	
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Ray || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return;
	}
}

//球とOBBの衝突判定
void CollisionSystem::CheackCollisionSphereAndOBB(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	//形状再確認
	if (collider_01_->GetNarrowCollider().shape != ColliderShapeTag::Sphere || collider_02_->GetNarrowCollider().shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return;
	}
}