#ifndef BROAD_COLLIDER_H
#define BROAD_COLLIDER_H

#include "../../../Constant/ConstantValue.h"
#include "../../../Utility/Vec3.h"

struct BroadCollider
{
public:
	//コンストラクタ
	BroadCollider(Vec3 min_vertex_, Vec3 max_vertex_) :
		min_vertex(min_vertex_),
		max_vertex(max_vertex_)
	{
	}

	//最小頂点
	Vec3 min_vertex{ Vec3::Zero() };

	//最大頂点
	Vec3 max_vertex{ Vec3::Zero() };
};
#endif