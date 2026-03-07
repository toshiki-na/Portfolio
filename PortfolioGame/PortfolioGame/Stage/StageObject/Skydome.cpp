#include "Skydome.h"
#include <DxLib.h>
#include "../../ResourceManager/ResourceSystemManager.h"

//•`‰æ
void Skydome::Draw()const
{
	//‹ó‚Ì•`‰æ
	DxLib::MV1DrawModel(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Skydome));
}