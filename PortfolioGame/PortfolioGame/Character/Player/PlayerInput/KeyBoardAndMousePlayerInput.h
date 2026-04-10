#ifndef KEYBOARD_AND_MOUSE_PLAYER_INPUT_H
#define KEYBOARD_AND_MOUSE_PLAYER_INPUT_H

#include "IPlayerInput.h"
#include "../../../Utility/Vec3.h"
#include "../../../Input/InputSystems.h"
#include "../../../Input/MouseInput.h"
#include "../../../Input/KeyBoardInput.h"

class KeyBoardAndMousePlayerInput : public IPlayerInput
{
public:
	//コンストラクタ
	KeyBoardAndMousePlayerInput() : 
		mouse_input(InputSystems::Instance().GetMouseInput()),
		keyboard_input(InputSystems::Instance().GetKeyBoardInput())
	{
	};

	//移動方向入力の取得
	Vec3 GetMoveInput() const
	{
		Vec3 result = Vec3::Zero();

	if (keyboard_input.IsHeld(KeyBoardInput::Key::W))
		{
			result.y += 1.0f;
		}

		if (keyboard_input.IsHeld(KeyBoardInput::Key::S))
		{
			result.y -= 1.0f;
		}

		if (keyboard_input.IsHeld(KeyBoardInput::Key::A))
		{
			result.x -= 1.0f;
		}

		if (keyboard_input.IsHeld(KeyBoardInput::Key::D))
		{
			result.x += 1.0f;
		}

		if (result.LengthSq() > 0.0f)
		{
			result = result.Normalized();
		}

		return result;
	}

	//ジャンプ入力の取得
	bool GetJumpInput() const
	{
		return keyboard_input.IsJustPressed(KeyBoardInput::Key::SPACE);
	}

	//攻撃入力の取得
	bool GetAttackInput() const
	{
		return mouse_input.IsJustPressed(MouseInput::Button::Left);
	}

	//回避入力の取得
	bool GetAvoidInput() const
	{
		return keyboard_input.IsJustPressed(KeyBoardInput::Key::LSHIFT);
	}


private:
	MouseInput& mouse_input;
	KeyBoardInput& keyboard_input;
};
#endif