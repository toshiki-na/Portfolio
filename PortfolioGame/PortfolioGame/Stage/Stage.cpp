#include "Stage.h"

//•`‰æ
void Stage::Update()
{
	//ƒXƒe[ƒW•`‰æƒRƒ“ƒ|[ƒlƒ“ƒg“o˜^
	for (auto& StageObject : context.stage_objects)
	{
		rendering_system.Register(StageObject->GetRender());
	}
}