#ifndef GROUND_H
#define GROUND_H

#include "StageObjectBase.h"
#include <DXLib.h>
#include "../../Utility/Vec3.h"
#include "../../ResourceManager/ResourceSystemManager.h"

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
		//衝突判定の準備
		DxLib::MV1SetupCollInfo(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Ground));
	};
};
#endif