#include "Ground.h"
#include <DxLib.h>
#include "../../ResourceManager/ResourceSystemManager.h"

//•`‰æ
void Ground::Draw()const
{
	//’n–Ê‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Ground));
}