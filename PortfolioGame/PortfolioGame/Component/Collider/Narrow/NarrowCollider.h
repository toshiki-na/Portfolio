#ifndef NARROW_COLLIDER_H
#define NARROW_COLLIDER_H

#include "../../../Utility/Vec3.h"

struct NarrowCollider
{
public:
	//コンストラクタ
	NarrowCollider(Vec3 positon_ = Vec3::Zero(), Vec3 scale_ = Vec3::Zero()) :
		positon(positon_),
		scale(scale_)
	{
	}

	//位置座標
	Vec3 positon;

	//立幅・横幅スケール
	Vec3 scale;
};
#endif