#include "Player.h"
#include <DXLib.h>
#include "../../Constant/Tag.h"
#include "../../ResourceManager/ResourceSystems.h"
#include "../../TimeManager/TimeManager.h"

void Player::Update()
{
	if (CheckHitKey(KEY_INPUT_W))
	{
		position += forward * speed * TimeManager::Instance().GetDeltaTime();
	}
}

void Player::Draw()
{
	MV1DrawModel(ResourceSystems::Instance().GetModelManager().GetHandle(ModelTag::Player));
}