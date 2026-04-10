#include "MovementComponent.h"
#include <cmath>
#include "../../Utility/Vec3.h"
#include "../../TimeManager/TimeManager.h"

//位置情報セット
void MovementComponent::SetTransformComponent(TransformComponent* transform_)
{
	transform = transform_;
}


//更新
void MovementComponent::Update()
{
	if (transform != nullptr)
	{
		//移動方向の取得
		Vec3 move_vec = move_vec_computer->GetVector();

		////前方を入力方向に調整
		//transform.SetForward(move_vec);
		//transform.SetYawRadian(atan2f(move_vec.z, move_vec.x));

		//次フレームの移動先計算
		Vec3 next_positon = transform->GetPosition() + (move_vec * speed * TimeManager::Instance().GetDeltaTime());

		//地形との当たり判定
		//地形との判定実装

		//移動確定
		transform->SetPosition(next_positon);
	}
}