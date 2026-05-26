#ifndef BROAD_COLLIDER_H
#define BROAD_COLLIDER_H

#include "../../../Utility/Vec3.h"
#include "../Broad/BroadCollider.h"

struct BroadCollider
{
public:
	//コンストラクタ
	BroadCollider(Vec3 positon_ = Vec3::Zero(), Vec3 scale_ = Vec3::Zero()) :
		positon(positon_),
		scale(scale_)
	{
		//y軸方向にはスケールの半分追加
		positon.y += scale.y / 2.0f;
	}

	//位置座標
	Vec3 positon;

	//立幅・横幅スケール
	Vec3 scale;
};
#endif