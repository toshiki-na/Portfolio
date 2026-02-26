#ifndef INTERFACE_PLAYER_INPUT_H
#define INTERFACE_PLAYER_INPUT_H

#include "../../../Utility/Vec3.h"

class IPlayerInput
{
public:
	//デストラクタ
	virtual ~IPlayerInput() = default;

	//移動方向入力の取得
	virtual Vec3 GetMoveInput() const = 0;

	//ジャンプ入力の取得
	virtual bool GetJumpInput() const = 0;

	//攻撃入力の取得
	virtual bool GetAttackInput() const = 0;

	//回避入力の取得
	virtual bool GetAvoidInput() const = 0;
};
#endif