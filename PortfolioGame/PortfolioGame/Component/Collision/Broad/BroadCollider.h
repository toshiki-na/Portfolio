#ifndef BROAD_COLLIDER_H
#define BROAD_COLLIDER_H

#include "../../../Utility/Vec3.h"
#include "../Broad/BroadCollider.h"

struct BroadCollider
{
public:
	//コンストラクタ
	BroadCollider(Vec3 positon_ = Vec3::Zero(), Vec3 scale_ = Vec3::Zero(), float object_height_ = 0.0f) :
		positon(positon_),
		scale(scale_)
	{
	}

	//位置座標
	Vec3 positon;

	//立幅・横幅スケール
	Vec3 scale;

	//オブジェクトの高さ
	float object_height{ 0.0f };
};
#endif