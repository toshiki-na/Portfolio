#include "MouseInput.h"
#include <DXLib.h>

//毎フレームの最初に実行
void MouseInput::BeginFrame()
{
	//現在のクリック状態の取得
	now_button_state = DxLib::GetMouseInput();

	//現在のマウス座標の取得
	DxLib::GetMousePoint(&now_x, &now_y);

	//移動方向ベクトルの計算
	move_direction.x = now_x - base_x;
	move_direction.y = now_y - base_y;
	move_direction.z = 0.0f;

	//正規化
	move_direction = move_direction.Normalized();
}

//毎フレームの最後に実行
void MouseInput::EndFrame()
{
	//現在フレームの状態を前フレーム情報として保存
	pre_button_state = now_button_state;

	//マウスの位置を基準座標に戻す
	DxLib::SetMousePoint(base_x, base_y);
}

//押されたフレームかどうかの取得
bool MouseInput::IsJustPressed(MouseInput::Button button_)const
{
	bool result = false;

	if ((pre_button_state & ToDxLibMask(button_)) == 0 && (now_button_state & ToDxLibMask(button_)) != 0)
	{
		result = true;
	}

	return result;
}

//押され続けているフレームかどうかの取得
bool MouseInput::IsHeld(MouseInput::Button button_) const
{
	bool result = false;

	if ((pre_button_state & ToDxLibMask(button_)) != 0 && (now_button_state & ToDxLibMask(button_)) != 0)
	{
		result = true;
	}

	return result;
}

//離されたフレームかどうかの取得
bool MouseInput::IsJustReleased(MouseInput::Button button_) const
{
	bool result = false;

	if ((pre_button_state & ToDxLibMask(button_)) != 0 && (now_button_state & ToDxLibMask(button_)) == 0)
	{
		result = true;
	}

	return result;
}

//マウスの移動方向の取得
Vec3 MouseInput::GetMouseMoveDirection() const
{
	return move_direction;
}

//各ボタンのビットマスク値を取得
int MouseInput::ToDxLibMask(Button button_) const
{
	switch (button_)
	{
	case Button::Left:
		return MOUSE_INPUT_LEFT;
		break;

	case Button::Right:
		return MOUSE_INPUT_RIGHT;
		break;

	case Button::Middle:
		return MOUSE_INPUT_MIDDLE;
		break;
	}
}
