#ifndef NARROW_COLLIDER_H
#define NARROW_COLLIDER_H

#include "../../../Constant/Tag.h"
#include "../../../Utility/Vec3.h"
#include "../../../Utility/Quaternion.h"

struct NarrowCollider
{
public:
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

	//直方体用
	//サイズ
	Vec3 scale{ 0.0f };
	//回転
	Quaternion rotate{ Quaternion::Identity() };
};
#endif