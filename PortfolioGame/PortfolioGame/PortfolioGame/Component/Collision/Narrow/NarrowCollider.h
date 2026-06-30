#ifndef NARROW_COLLIDER_H
#define NARROW_COLLIDER_H

#include "../../../Constant/Tag.h"
#include "../../../Utility/Vec3.h"
#include "../../../Utility/Quaternion.h"

struct NarrowCollider
{
public:
	//コンストラクタ
	//形状不明時はエラー
	NarrowCollider() = delete;
	//線分
	NarrowCollider(Vec3 start_, Vec3 end_):
		start(start_),
		end(end_)
	{
		shape = ColliderShapeTag::Ray;
	}
	//球
	NarrowCollider(Vec3 position_, float radius_):
		position(position_),
		radius(radius_)
	{
		shape = ColliderShapeTag::Sphere;
	}
	//OBB
	NarrowCollider(Vec3 position_, Vec3 half_scale_, Quaternion rotate_):
		position(position_),
		half_scale(half_scale_),
		rotate(rotate_)
	{
		shape = ColliderShapeTag::Box;
	}

	//形状タグ
	ColliderShapeTag shape;

	//情報
	//位置情報
	Vec3 position{ Vec3::Zero() };

	//線分用
	//始点
	Vec3 start{ Vec3::Zero()};
	//終点
	Vec3 end{ Vec3::Zero() };

	//球用
	//半径
	float radius{ 0.0f };

	//OBB用
	//サイズ(辺の長さの半分)
	Vec3 half_scale{ 0.0f };
	//回転
	Quaternion rotate{ Quaternion::Identity() };
};
#endif