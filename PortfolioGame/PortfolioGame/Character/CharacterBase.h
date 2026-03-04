#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include <memory>
#include "../Utility/Vec3.h"
#include "../Component/Movement/MovementComponent.h"

class CharacterBase
{
public:
	//コンストラクタ
	CharacterBase(MovementComponent movement_) :
		movement(std::move(movement_))
	{
	}

	//更新
	virtual void Update() = 0;

	//描画
	virtual void Draw() = 0;

	//生存状態取得
	bool GetActive() const
	{
		return active;
	}

protected:
	//生存フラグ
	bool active{ true };

	//移動コンポーネント
	MovementComponent movement;
};
#endif