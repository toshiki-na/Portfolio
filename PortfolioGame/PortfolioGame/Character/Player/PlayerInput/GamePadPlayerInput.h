#ifndef GAMEPAD_PLAYER_INPUT_H
#define GAMEPAD_PLAYER_INPUT_H

#include "IPlayerInput.h"
#include "../../../Utility/Vec3.h"
#include "../../../Input/InputSystems.h"
#include "../../../Input/GamePadInput.h"

class GamePadPlayerInput : public IPlayerInput
{
public:
	//コンストラクタ
	GamePadPlayerInput() :
		input(InputSystems::Instance().GetGamePadInput())
	{
	}

	//移動方向入力の取得
	Vec3 GetMoveInput() const override
	{
		return input.GetLeftStick();
	}

	//ジャンプ入力の取得
	bool GetJumpInput() const override
	{
		if (input.IsJustPressed(GamePadInput::Button::X) || input.IsJustPressed(GamePadInput::Button::Y))
		{
			return true;
		}

		return false;
	}

	//攻撃入力の取得
	bool GetAttackInput() const override
	{
		return input.IsJustPressed(GamePadInput::Button::B);
	}

	//回避入力の取得
	bool GetAvoidInput() const override
	{
		return input.IsJustPressed(GamePadInput::Button::A);
	}


private:
	GamePadInput& input;
};
#endif