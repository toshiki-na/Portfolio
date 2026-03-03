#include "Player.h"
#include <DXLib.h>
#include "../../Constant/Tag.h"
#include "../../ResourceManager/ResourceSystemManager.h"

//XV
void Player::Update()
{
}

//•`‰æ
void Player::Draw()
{
	DxLib::MV1DrawModel(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Player));
}