#include "Player.h"
#include <DXLib.h>
#include "../../Constant/Tag.h"
#include "../../Input/InputSystems.h"
#include "../../ResourceManager/ResourceSystemManager.h"
#include "../../TimeManager/TimeManager.h"

//XV
void Player::Update()
{
	//ˆÚ“®
	Move();
}

//•`‰æ
void Player::Draw()
{
	DxLib::MV1DrawModel(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Player));
}

//ˆÚ“®
void Player::Move()
{

}
