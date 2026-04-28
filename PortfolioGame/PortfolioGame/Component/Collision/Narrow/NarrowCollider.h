#ifndef NARROW_COLLIDER_H
#define NARROW_COLLIDER_H

#include <unordered_map>
#include "../../../Constant/Tag.h"
#include "../../../Utility/Vec3.h"

struct NarrowCollider
{
public:
	//コンストラクタ
	NarrowCollider() = default;

	//形状タグ
	ColliderShapeTag shape;

	//情報
	std::unordered_map<ColliderInformationTag, Vec3> information;
};
#endif