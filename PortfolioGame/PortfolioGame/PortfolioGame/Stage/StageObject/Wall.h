#ifndef WALL_H
#define WALL_H

#include "StageObjectBase.h"
#include <DXLib.h>
#include "../../Utility/Vec3.h"
#include "../../ResourceManager/ResourceSystemManager.h"

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
		//衝突判定の準備
		DxLib::MV1SetupCollInfo(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Wall));
	};
};
#endif