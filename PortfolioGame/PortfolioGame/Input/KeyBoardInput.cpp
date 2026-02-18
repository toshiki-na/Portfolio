#include "KeyBoardInput.h"
#include <string>
#include <DxLib.h>

//毎フレームの最初に実行
void KeyBoardInput::BeginFrame()
{
	//全キーの入力状態を取得
	DxLib::GetHitKeyStateAll(now_key_state);
}

//毎フレームの最後に実行
void KeyBoardInput::EndFrame()
{
	//現在フレームの状態を前フレーム情報として保存
	std::memcpy(pre_key_state, now_key_state, sizeof(pre_key_state));
}

//押されたフレームかどうかの取得
bool KeyBoardInput::IsJustPressed(KeyBoardInput::Key key_) const
{
	bool result = false;

	if (pre_key_state[ToDxLibMask(key_)] == 0 && now_key_state[ToDxLibMask(key_)] == 1)
	{
		result = true;
	}
	
	return result;
}

//押され続けているフレームかどうかの取得
bool KeyBoardInput::IsHeld(KeyBoardInput::Key key_) const
{
	bool result = false;

	if (pre_key_state[ToDxLibMask(key_)] == 1 && now_key_state[ToDxLibMask(key_)] == 1)
	{
		result = true;
	}

	return result;
}

//離されたフレームかどうかの取得
bool KeyBoardInput::IsJustReleased(KeyBoardInput::Key key_) const
{
	bool result = false;

	if (pre_key_state[ToDxLibMask(key_)] == 1 && now_key_state[ToDxLibMask(key_)] == 0)
	{
		result = true;
	}

	return result;
}

//各ボタンのビットマスク値を取得
int KeyBoardInput::ToDxLibMask(Key key_) const
{
	switch (key_)
	{
	case Key::A:
		return KEY_INPUT_A;
		break;

	case Key::B:
		return KEY_INPUT_B;
		break;

	case Key::C:
		return KEY_INPUT_C;
		break;

	case Key::D:
		return KEY_INPUT_D;
		break;

	case Key::E:
		return KEY_INPUT_E;
		break;

	case Key::F:
		return KEY_INPUT_F;
		break;

	case Key::G:
		return KEY_INPUT_G;
		break;

	case Key::H:
		return KEY_INPUT_H;
		break;

	case Key::I:
		return KEY_INPUT_I;
		break;

	case Key::J:
		return KEY_INPUT_J;
		break;

	case Key::K:
		return KEY_INPUT_K;
		break;

	case Key::L:
		return KEY_INPUT_L;
		break;

	case Key::M:
		return KEY_INPUT_M;
		break;

	case Key::N:
		return KEY_INPUT_N;
		break;

	case Key::O:
		return KEY_INPUT_O;
		break;

	case Key::P:
		return KEY_INPUT_P;
		break;

	case Key::Q:
		return KEY_INPUT_Q;
		break;

	case Key::R:
		return KEY_INPUT_R;
		break;

	case Key::S:
		return KEY_INPUT_S;
		break;

	case Key::T:
		return KEY_INPUT_T;
		break;

	case Key::U:
		return KEY_INPUT_U;
		break;

	case Key::V:
		return KEY_INPUT_V;
		break;

	case Key::W:
		return KEY_INPUT_W;
		break;

	case Key::X:
		return KEY_INPUT_X;
		break;

	case Key::Y:
		return KEY_INPUT_Y;
		break;

	case Key::Z:
		return KEY_INPUT_Z;
		break;

	case Key::ZERO:
		return KEY_INPUT_0;
		break;

	case Key::ONE:
		return KEY_INPUT_1;
		break;

	case Key::TWO:
		return KEY_INPUT_2;
		break;

	case Key::THREE:
		return KEY_INPUT_3;
		break;

	case Key::FOUR:
		return KEY_INPUT_4;
		break;

	case Key::FIVE:
		return KEY_INPUT_5;
		break;

	case Key::SIX:
		return KEY_INPUT_6;
		break;

	case Key::SEVEN:
		return KEY_INPUT_7;
		break;

	case Key::EIGHT:
		return KEY_INPUT_8;
		break;

	case Key::NINE:
		return KEY_INPUT_9;
		break;

	case Key::UP:
		return KEY_INPUT_UP;
		break;

	case Key::DOWN:
		return KEY_INPUT_DOWN;
		break;

	case Key::LEFT:
		return KEY_INPUT_LEFT;
		break;

	case Key::RIGHT:
		return KEY_INPUT_RIGHT;
		break;

	case Key::BACKSPACE:
		return KEY_INPUT_BACK;
		break;

	case Key::TAB:
		return KEY_INPUT_TAB;
		break;

	case Key::ENTER:
		return KEY_INPUT_RETURN;
		break;

	case Key::LSHIFT:
		return KEY_INPUT_LSHIFT;
		break;

	case Key::RSHIFT:
		return KEY_INPUT_RSHIFT;
		break;

	case Key::LCTRL:
		return KEY_INPUT_LCONTROL;
		break;

	case Key::RCTRL:
		return KEY_INPUT_RCONTROL;
		break;

	case Key::ESC:
		return KEY_INPUT_ESCAPE;
		break;

	case Key::SPACE:
		return KEY_INPUT_SPACE;
		break;

	case Key::PGUP:
		return KEY_INPUT_PGUP;
		break;

	case Key::PGDN:
		return KEY_INPUT_PGDN;
		break;

	case Key::END:
		return KEY_INPUT_END;
		break;

	case Key::HOME:
		return KEY_INPUT_HOME;
		break;

	case Key::INSERT:
		return KEY_INPUT_INSERT;
		break;

	case Key::DEL:
		return KEY_INPUT_DELETE;
		break;

	case Key::LALT:
		return KEY_INPUT_LALT;
		break;

	case Key::RALT:
		return KEY_INPUT_RALT;
		break;

	case Key::SCROLL:
		return KEY_INPUT_SCROLL;
		break;

	case Key::CAPSLOCK:
		return KEY_INPUT_CAPSLOCK;
		break;

	case Key::PAUSE:
		return KEY_INPUT_PAUSE;
		break;

	case Key::MINUS:
		return KEY_INPUT_MINUS;
		break;

	case Key::PREVTRACK:
		return KEY_INPUT_PREVTRACK;
		break;

	case Key::YEN:
		return KEY_INPUT_YEN;
		break;

	case Key::AT:
		return KEY_INPUT_AT;
		break;

	case Key::LBRACKET:
		return KEY_INPUT_LBRACKET;
		break;

	case Key::SEMICOLON:
		return KEY_INPUT_SEMICOLON;
		break;

	case Key::COLON:
		return KEY_INPUT_COLON;
		break;

	case Key::RBRACKET:
		return KEY_INPUT_RBRACKET;
		break;

	case Key::COMMA:
		return KEY_INPUT_COMMA;
		break;

	case Key::PERIOD:
		return KEY_INPUT_PERIOD;
		break;

	case Key::SLASH:
		return KEY_INPUT_SLASH;
		break;

	case Key::BACKSLASH:
		return KEY_INPUT_BACKSLASH;
		break;

	case Key::NUM_PAD_0:
		return KEY_INPUT_NUMPAD0;
		break;

	case Key::NUM_PAD_1:
		return KEY_INPUT_NUMPAD1;
		break;

	case Key::NUM_PAD_2:
		return KEY_INPUT_NUMPAD2;
		break;

	case Key::NUM_PAD_3:
		return KEY_INPUT_NUMPAD3;
		break;

	case Key::NUM_PAD_4:
		return KEY_INPUT_NUMPAD4;
		break;

	case Key::NUM_PAD_5:
		return KEY_INPUT_NUMPAD5;
		break;

	case Key::NUM_PAD_6:
		return KEY_INPUT_NUMPAD6;
		break;

	case Key::NUM_PAD_7:
		return KEY_INPUT_NUMPAD7;
		break;

	case Key::NUM_PAD_8:
		return KEY_INPUT_NUMPAD8;
		break;

	case Key::NUM_PAD_9:
		return KEY_INPUT_NUMPAD9;
		break;

	case Key::ADD:
		return KEY_INPUT_ADD;
		break;

	case Key::SUBTRACT:
		return KEY_INPUT_SUBTRACT;
		break;

	case Key::DIVIDE:
		return KEY_INPUT_DIVIDE;
		break;

	case Key::MULTIPLY:
		return KEY_INPUT_MULTIPLY;
		break;

	case Key::DECIMAL:
		return KEY_INPUT_DECIMAL;
		break;

	case Key::NUM_PAD_ENTER:
		return KEY_INPUT_NUMPADENTER;
		break;

	case Key::F1:
		return KEY_INPUT_F1;
		break;

	case Key::F2:
		return KEY_INPUT_F2;
		break;

	case Key::F3:
		return KEY_INPUT_F3;
		break;

	case Key::F4:
		return KEY_INPUT_F4;
		break;

	case Key::F5:
		return KEY_INPUT_F5;
		break;

	case Key::F6:
		return KEY_INPUT_F6;
		break;

	case Key::F7:
		return KEY_INPUT_F7;
		break;

	case Key::F8:
		return KEY_INPUT_F8;
		break;

	case Key::F9:
		return KEY_INPUT_F9;
		break;

	case Key::F10:
		return KEY_INPUT_F10;
		break;

	case Key::F11:
		return KEY_INPUT_F11;
		break;

	case Key::F12:
		return KEY_INPUT_F12;
		break;
	}
}