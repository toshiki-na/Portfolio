#include "NarrowCollisionComputer.h"
#include <cmath>
#include "../../Utility/Vec3.h"
#include "../../Utility/Quaternion.h"

//線分と線分の衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndRay(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//未実装

	//衝突していない
	return false;
}

//球と球の衝突判定
bool NarrowCollisionComputer::CheackCollisionSphereAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Sphere || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//距離の2乗
	float distance_sq = (collider_02_.position - collider_01_.position).LengthSq();

	//半径の合計の2乗
	float total_radius_sq = (collider_01_.radius + collider_02_.radius) * (collider_01_.radius + collider_02_.radius);

	//衝突判定
	if (distance_sq <= total_radius_sq)
	{
		//衝突している
		return true;
	}

	//衝突していない
	return false;
}

//OBBとOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionOBBAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//未実装
	
	//衝突していない
	return false;
}

//線分と球の衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//線分のベクトル
	Vec3 ray = collider_01_.end - collider_01_.start;

	//線分の長さの2乗
	float ray_length_sq = ray.LengthSq();

	//線分の長さがほぼ0なら衝突不可で判定終了
	if (ray_length_sq <= FLT_EPSILON)
	{
		return false;
	}

	//線分の直線上へ線分の始点から球の中心点へのベクトルを投影したながさ
	float projection_ray_start_to_closest_on_sphere = Vec3Math::Dot(collider_02_.position - collider_01_.start, ray);

	//投影した長さの線分の長さへの割合
	float projection_rate = projection_ray_start_to_closest_on_sphere / ray.LengthSq();

	//線分内に収める
	projection_rate = std::clamp(projection_rate, 0.0f, 1.0f);

	//線分上の球の中心点への最接近点
	Vec3 closest_position = collider_01_.start + projection_rate * ray;

	//線分上の球の中心点への最接近点と球の中心点の距離の2乗
	float distance_sq_closest_on_sphere_and_sphere = (closest_position - collider_02_.position).LengthSq();

	//線分上の最接近点が球内もしくは球表面上なら衝突
	if (distance_sq_closest_on_sphere_and_sphere <= collider_02_.radius * collider_02_.radius)
	{
		return true;
	}

	//衝突していない
	return false;
}

//線分とOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionRayAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//未実装

	//衝突していない
	return false;
}

//球とOBBの衝突判定
bool NarrowCollisionComputer::CheackCollisionSphereAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//未実装

	//衝突していない
	return false;
}