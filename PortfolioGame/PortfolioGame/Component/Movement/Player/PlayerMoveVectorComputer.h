#ifndef PLAYER_MOVE_VECTOR_COMPUTER_H
#define PLAYER_MOVE_VECTOR_COMPUTER_H

#include <memory>
#include "../../../Utility/Vec3.h"
#include "../IMoveVectorComputer.h"
#include "../../../Character/Player/PlayerInput/IPlayerInput.h"

class PlayerMoveVectorComputer : public IMoveVectorComputer
{
public:
	//コンストラクタ
	PlayerMoveVectorComputer(std::unique_ptr<IPlayerInput> input_) :
		input(std::move(input_))
	{
	}

	//移動方向の取得
	Vec3 GetVector() override
	{
		return input->GetMoveInput();
	}

private:
	//プレイヤー入力
	std::unique_ptr<IPlayerInput> input;
};
#endif