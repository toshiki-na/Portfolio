#include "Player.h"

//身体の衝突イベント関数
void Player::BodyHitFunction(ComponentLayer hit_object_layer_)
{
	switch (hit_object_layer_)
	{
	default:
		break;
	}

}

//武器の衝突イベント関数
void Player::WeaponHitFunction(ComponentLayer hit_object_layer_)
{
	//現状は武器は衝突時はなにもなし
	switch (hit_object_layer_)
	{
	default:
		break;
	}
}