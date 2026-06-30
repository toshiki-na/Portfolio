#ifndef STAGE_H
#define STAGE_H

#include "../Component/Render/RenderingSystem.h"
#include "StageContext/StageContext.h"

class Stage
{
public:
	//コンストラクタ
	Stage(RenderingSystem& rendering_system_):
		rendering_system(rendering_system_)
	{
	}

	//更新
	void Update();

private:
	//コンポーネントシステム
	//描画
	RenderingSystem& rendering_system;

	//ステージオブジェクト
	StageContext context;
};
#endif