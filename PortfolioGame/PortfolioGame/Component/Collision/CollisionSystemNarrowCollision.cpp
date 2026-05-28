#include "CollisionSystem.h"

//線分と線分の衝突判定
bool CollisionSystem::CheackCollisionRayAndRay(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Ray)
	{
		//形状不一致で衝突判定終了
		return false;
	}
}

//球と球の衝突判定
bool CollisionSystem::CheackCollisionSphereAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Sphere || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//距離の2乗
	float distance_sq = (collider_01_.information[ColliderInformationTag::Position] - collider_02_.information[ColliderInformationTag::Position]).LengthSq();

	//半径の合計の2乗
	float total_radius_sq = (collider_01_.information[ColliderInformationTag::Radius] + collider_02_.information[ColliderInformationTag::Radius]).LengthSq();

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
bool CollisionSystem::CheackCollisionOBBAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Box || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//直方体2つ(8頂点の塊で疑似的に直方体扱いとする)
	Vec3 vertices_01[8] =
	{
		{ 0.5f,  0.5f,  0.5f}, //右上奥
		{ 0.5f,  0.5f, -0.5f}, //右上手前
		{-0.5f,  0.5f, -0.5f}, //左上手前
		{-0.5f,  0.5f,  0.5f}, //左上奥

		{ 0.5f, -0.5f,  0.5f}, //右下奥
		{ 0.5f, -0.5f, -0.5f}, //右下手前
		{-0.5f, -0.5f, -0.5f}, //左下手前
		{-0.5f, -0.5f,  0.5f}, //左下奥
	};
	Vec3 vertices_02[8] =
	{
		{ 0.5f,  0.5f,  0.5f}, //右上奥
		{ 0.5f,  0.5f, -0.5f}, //右上手前
		{-0.5f,  0.5f, -0.5f}, //左上手前
		{-0.5f,  0.5f,  0.5f}, //左上奥

		{ 0.5f, -0.5f,  0.5f}, //右下奥
		{ 0.5f, -0.5f, -0.5f}, //右下手前
		{-0.5f, -0.5f, -0.5f}, //左下手前
		{-0.5f, -0.5f,  0.5f}, //左下奥
	};


}

//線分と球の衝突判定
bool CollisionSystem::CheackCollisionRayAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Sphere)
	{
		//形状不一致で衝突判定終了
		return false;
	}
}

//線分とOBBの衝突判定
bool CollisionSystem::CheackCollisionRayAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Ray || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}

	//直方体(8頂点の塊で疑似的に直方体扱いとする)
	Vec3 vertices[8] =
	{
		{ 0.5f,  0.5f,  0.5f}, //右上奥
		{ 0.5f,  0.5f, -0.5f}, //右上手前
		{-0.5f,  0.5f, -0.5f}, //左上手前
		{-0.5f,  0.5f,  0.5f}, //左上奥

		{ 0.5f, -0.5f,  0.5f}, //右下奥
		{ 0.5f, -0.5f, -0.5f}, //右下手前
		{-0.5f, -0.5f, -0.5f}, //左下手前
		{-0.5f, -0.5f,  0.5f}, //左下奥
	};

	//スケール倍
	for (auto& Vertex : vertices)
	{
		Vertex *= collider_02_.information[ColliderInformationTag::Scale];
	}
}

//球とOBBの衝突判定
bool CollisionSystem::CheackCollisionSphereAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_)
{
	//形状再確認
	if (collider_01_.shape != ColliderShapeTag::Sphere || collider_02_.shape != ColliderShapeTag::Box)
	{
		//形状不一致で衝突判定終了
		return false;
	}
}