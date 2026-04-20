#ifndef GROUND_H
#define GROUND_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Ground : public StageObjectBase
{
public:
	//コンストラクタ
	Ground(TransformComponent& transform_, RenderComponent& render_) :
		StageObjectBase(
			transform_,
			render_
		)
	{
	};
};
#endif