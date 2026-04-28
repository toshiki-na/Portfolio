#ifndef BROAD_COLLIDER_H
#define BROAD_COLLIDER_H

#include <unordered_map>
#include "../../../Constant/Tag.h"
#include "../../../Utility/Vec3.h"

struct BroadCollider
{
public:
	//コンストラクタ
	BroadCollider() = default;

	//形状タグ
	ColliderShapeTag shape;

	//情報
	std::unordered_map<ColliderInformationTag, Vec3> information;
};
#endif