#include "Enemy.h"

//身体の衝突イベント関数
void Enemy::BodyHitFunction(ComponentLayer hit_object_layer_)
{
	switch (hit_object_layer_)
	{
	default:
		break;
	}

}

//武器の衝突イベント関数
void Enemy::WeaponHitFunction(ComponentLayer hit_object_layer_)
{
	//現状は武器は衝突時はなにもなし
	switch (hit_object_layer_)
	{
	default:
		break;
	}
}