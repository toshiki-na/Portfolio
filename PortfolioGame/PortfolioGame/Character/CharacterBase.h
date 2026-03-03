#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../Utility/Vec3.h"
#include "../Component/Movement/MovementComponent.h"

class CharacterBase
{
public:
	//コンストラクタ
	CharacterBase()
	{
	}

	//デストラクタ
	virtual ~CharacterBase() = default;

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

	//位置
	MovementComponent& movement;
};
#endif