#include "Player.h"
#include <DXLib.h>
#include "../../Constant/Tag.h"
#include "../../ResourceManager/ResourceSystems.h"

void Player::Update()
{
}

void Player::Draw()
{
	MV1DrawModel(ResourceSystems::Instance()->GetModelManager().GetHandle(ModelTag::Player));
}