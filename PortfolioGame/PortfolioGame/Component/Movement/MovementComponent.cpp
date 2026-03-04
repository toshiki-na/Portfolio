#include "MovementComponent.h"
#include <cmath>
#include "../../Utility/Vec3.h"
#include "../../TimeManager/TimeManager.h"

//更新
void MovementComponent::Update()
{
	//移動方向の取得
	Vec3 move_vec = move_vec_computer->GetVector();

	forward = move_vec;

	//次フレームの移動先計算
	Vec3 next_positon = position + (move_vec * speed * TimeManager::Instance().GetDeltaTime());

	//地形との当たり判定
	//地形との判定実装

	//移動確定
	position = next_positon;
}

//前方向計算
void MovementComponent::CalcYawRadian()
{
	yaw_radian = atan2f(forward.z, forward.x);
}