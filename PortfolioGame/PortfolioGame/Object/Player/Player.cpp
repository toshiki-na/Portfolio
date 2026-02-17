#include "Player.h"
#include <DXLib.h>
#include "../../Constant/Tag.h"
#include "../../ResourceManager/ResourceSystems.h"
#include "../../TimeManager/TimeManager.h"

void Player::Update()
{
	//移動
	Move();
}

void Player::Draw()
{
	MV1DrawModel(ResourceSystems::Instance().GetModelManager().GetHandle(ModelTag::Player));
}

//移動
void Player::Move()
{
	//Wキーで前進
	if (CheckHitKey(KEY_INPUT_W))
	{
		position += forward * speed * TimeManager::Instance().GetDeltaTime();
	}

	//
}
