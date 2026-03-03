#ifndef PLAYER_MOVE_VECTOR_COMPUTER_H
#define PLAYER_MOVE_VECTOR_COMPUTER_H

#include "../../Utility/Vec3.h"
#include "IMoveVectorComputer.h"
#include "../../Character/Player/PlayerInput/IPlayerInput.h"

class PlayerMoveVectorComputer : public IMoveVectorComputer
{
public:
	//コンストラクタ
	PlayerMoveVectorComputer()
	{
	}

	//デストラクタ
	~PlayerMoveVectorComputer() override = default;

	//移動方向の取得
	Vec3 GetVector() override;

private:

};
#endif