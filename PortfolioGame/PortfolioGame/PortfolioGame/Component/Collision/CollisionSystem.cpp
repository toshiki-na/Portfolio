#include "CollisionSystem.h"
#include <vector>
#include <algorithm>

//簡易衝突判定の登録
void CollisionSystem::Register(ColliderComponent* component_)
{
	registered_colliders.push_back(component_);
}

//更新
void CollisionSystem::Update()
{
	//衝突判定開始(デバッグ用)
	debug_view.CollisionStart();
	
	//衝突判定を取るオブジェクトが2つ以上の時のみ衝突判定する
	if (registered_colliders.size() >= 2)
	{
		//簡易衝突判定
		SAPBroadCollision();

		//衝突判定
		NarrowCollision();
	}

	//衝突判定終了(デバッグ用)
	debug_view.CollisionEnd();
}

//SweepAndPrune簡易衝突判定
void CollisionSystem::SAPBroadCollision()
{
	//x軸最小頂点をソート
	SortCollidersXMinimum();

	for (int i = 0; i < registered_colliders.size() - 1; ++i)
	{
		for (int j = i; j < registered_colliders.size(); ++j)
		{
			//簡易衝突判定回数計測(デバッグ用)
			debug_view.CountUpBroadCollisonCount();

			//X軸重なり判定
			if (IsOverRapX(registered_colliders[i], registered_colliders[j]))
			{
				//ZY軸重なり判定
				if(IsOverRapZ(registered_colliders[i], registered_colliders[j]) && IsOverRapY(registered_colliders[i], registered_colliders[j]))
				{
					//簡易衝突判定で衝突しているので厳密な衝突判定用ペアに登録
					narrow_collision_pairs.push_back({ registered_colliders[i], registered_colliders[j]});
				}
			}
			//X軸方向はソート済みのため最初に重なりがなくなった時点で以降はすべて判定不要
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
		[](ColliderComponent* collider_01_, ColliderComponent* collider_02_)
		{
			return collider_01_->GetBroadCollider().min_vertex.x < collider_02_->GetBroadCollider().min_vertex.x;
		}
	);
}

//X軸方向の重なり判定
bool CollisionSystem::IsOverRapX(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	if (collider_01_->GetBroadCollider().max_vertex.x < collider_02_->GetBroadCollider().min_vertex.x || collider_01_->GetBroadCollider().min_vertex.x > collider_02_->GetBroadCollider().max_vertex.x)
	{
		return false;
	}

	return true;
}

//Y軸方向の重なり判定
bool CollisionSystem::IsOverRapY(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	if (collider_01_->GetBroadCollider().max_vertex.y < collider_02_->GetBroadCollider().min_vertex.y || collider_01_->GetBroadCollider().min_vertex.y > collider_02_->GetBroadCollider().max_vertex.y)
	{
		return false;
	}

	return true;
}

//Z軸方向の重なり判定
bool CollisionSystem::IsOverRapZ(ColliderComponent* collider_01_, ColliderComponent* collider_02_)
{
	if (collider_01_->GetBroadCollider().max_vertex.z < collider_02_->GetBroadCollider().min_vertex.z || collider_01_->GetBroadCollider().min_vertex.z > collider_02_->GetBroadCollider().max_vertex.z)
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
		//衝突判定回数計測
		debug_view.CountUpNarrowCollisonCount();

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

//デバッグ描画
void CollisionSystem::DebugDraw()
{
	debug_view.Draw();
}