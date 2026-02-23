#include "Stage.h"
#include <DxLib.h>
#include "../ResourceManager/ResourceSystems.h"

//•`‰æ
void Stage::Draw()
{
	//‹ó‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystems::Instance().GetModelManager().GetHandle(ModelTag::Skydome));

	//’n–Ê‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystems::Instance().GetModelManager().GetHandle(ModelTag::Ground));

	//•Ç‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystems::Instance().GetModelManager().GetHandle(ModelTag::Wall));
}