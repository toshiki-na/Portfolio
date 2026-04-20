#ifndef SKYDOME_H
#define SKYDOME_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Skydome : public StageObjectBase
{
public:
	//コンストラクタ
	Skydome(TransformComponent& transform_, RenderComponent& render_) :
		StageObjectBase(
			transform_,
			render_
		)
	{
	};
};
#endif