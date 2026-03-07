#include "Wall.h"
#include <DxLib.h>
#include "../../ResourceManager/ResourceSystemManager.h"

//•`‰æ
void Wall::Draw()const
{
	//•Ç‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Wall));
}