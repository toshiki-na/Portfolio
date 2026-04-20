#include "Stage.h"

//描画
void Stage::Update()
{
	//ステージ描画コンポーネント登録
	for (auto& StageObject : context.stage_objects)
	{
		rendering_system.Register(StageObject->GetRender(), ComponentLayer::Stage);
	}
}