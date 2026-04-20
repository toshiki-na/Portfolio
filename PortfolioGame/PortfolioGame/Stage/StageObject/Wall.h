#ifndef WALL_H
#define WALL_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Wall : public StageObjectBase
{
public:
	//コンストラクタ
	Wall(TransformComponent& transform_, RenderComponent& render_) :
		StageObjectBase(
			transform_,
			render_
		)
	{
	};
};
#endif