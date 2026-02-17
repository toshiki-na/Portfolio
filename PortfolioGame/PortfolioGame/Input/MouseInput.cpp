#include "MouseInput.h"
#include <DXLib.h>

//更新
void MouseInput::Update()
{
	//押下情報の更新
	UpdatePressInformation();

	//移動方向情報の更新
	//dUpdateMoveDirectionInformation();
}

//押されたフレームかどうかの取得
bool MouseInput::IsJustPressed(MouseInput::Button button_) const
{
	bool result = false;

	if (just_pressed_information.find(button_) != just_pressed_information.end())
	{
		result = just_pressed_information.find(button_)->second;
	}

	return result;
}

//押され続けているフレームかどうかの取得
bool MouseInput::IsPressed(MouseInput::Button button_) const
{
	bool result = false;

	if (pressed_information.find(button_) != pressed_information.end())
	{
		result = pressed_information.find(button_)->second;
	}

	return result;
}

//離されたフレームかどうかの取得
bool MouseInput::IsJustReleased(MouseInput::Button button_) const
{
	bool result = false;

	if (just_released_information.find(button_) != just_released_information.end())
	{
		result = just_released_information.find(button_)->second;
	}

	return result;
}

//マウスの移動方向の取得
Vec3 MouseInput::GetMouseMoveDirection() const
{
	return move_direction;
}

//情報の初期化
void MouseInput::InitializeInformation()
{
	pre_button_information[MouseInput::Button::Left] = 0;
	pre_button_information[MouseInput::Button::Right] = 0;
	pre_button_information[MouseInput::Button::Middle] = 0;

	now_button_information[MouseInput::Button::Left] = 0;
	now_button_information[MouseInput::Button::Right] = 0;
	now_button_information[MouseInput::Button::Middle] = 0;

	just_pressed_information[MouseInput::Button::Left] = false;
	just_pressed_information[MouseInput::Button::Right] = false;
	just_pressed_information[MouseInput::Button::Middle] = false;

	pressed_information[MouseInput::Button::Left] = false;
	pressed_information[MouseInput::Button::Right] = false;
	pressed_information[MouseInput::Button::Middle] = false;

	just_released_information[MouseInput::Button::Left] = false;
	just_released_information[MouseInput::Button::Right] = false;
	just_released_information[MouseInput::Button::Middle] = false;

	//初期のマウス座標の取得
	SetMousePoint(base_mouse_x, base_mouse_y);
}

//前フレームの押下情報をリセット
void MouseInput::ResetPressInformation()
{
	just_pressed_information[MouseInput::Button::Left] = false;
	just_pressed_information[MouseInput::Button::Right] = false;
	just_pressed_information[MouseInput::Button::Middle] = false;

	pressed_information[MouseInput::Button::Left] = false;
	pressed_information[MouseInput::Button::Right] = false;
	pressed_information[MouseInput::Button::Middle] = false;

	just_released_information[MouseInput::Button::Left] = false;
	just_released_information[MouseInput::Button::Right] = false;
	just_released_information[MouseInput::Button::Middle] = false;
}

//押下情報の更新
void MouseInput::UpdatePressInformation()
{
	//前フレームの押下状態情報をリセット
	ResetPressInformation();

	//現在の状態情報で更新
	now_button_information[MouseInput::Button::Left] = (GetMouseInput() & MOUSE_INPUT_LEFT);
	now_button_information[MouseInput::Button::Right] = (GetMouseInput() & MOUSE_INPUT_RIGHT);
	now_button_information[MouseInput::Button::Middle] = (GetMouseInput() & MOUSE_INPUT_MIDDLE);

	//各情報の更新
	int pre_info = 0;
	int now_info = 0;

	//左ボタン
	pre_info = pre_button_information[MouseInput::Button::Left];
	now_info = now_button_information[MouseInput::Button::Left];

	//前フレームが押されていなく今フレームが押されている
	if (pre_info == 0 && now_info != 0)
	{
		//押された瞬間 = true
		just_pressed_information[MouseInput::Button::Left] = true;
	}

	//前フレームも今フレームも押されている
	if (pre_info != 0 && now_info != 0)
	{
		//押されている = true
		pressed_information[MouseInput::Button::Left] = true;
	}

	//前フレームが押されていて今フレームは押されていない
	if (pre_info != 0 && now_info == 0)
	{
		//離された瞬間 = true
		just_released_information[MouseInput::Button::Left] = true;
	}

	//右ボタン
	pre_info = pre_button_information[MouseInput::Button::Right];
	now_info = now_button_information[MouseInput::Button::Right];

	//前フレームが押されていなく今フレームが押されている
	if (pre_info == 0 && now_info != 0)
	{
		//押された瞬間 = true
		just_pressed_information[MouseInput::Button::Right] = true;
	}

	//前フレームも今フレームも押されている
	if (pre_info != 0 && now_info != 0)
	{
		//押されている = true
		pressed_information[MouseInput::Button::Right] = true;
	}

	//前フレームが押されていて今フレームは押されていない
	if (pre_info != 0 && now_info == 0)
	{
		//離された瞬間 = true
		just_released_information[MouseInput::Button::Right] = true;
	}

	//中ボタン
	pre_info = pre_button_information[MouseInput::Button::Middle];
	now_info = now_button_information[MouseInput::Button::Middle];

	//前フレームが押されていなく今フレームが押されている
	if (pre_info == 0 && now_info != 0)
	{
		//押された瞬間 = true
		just_pressed_information[MouseInput::Button::Middle] = true;
	}

	//前フレームも今フレームも押されている
	if (pre_info != 0 && now_info != 0)
	{
		//押されている = true
		pressed_information[MouseInput::Button::Middle] = true;
	}

	//前フレームが押されていて今フレームは押されていない
	if (pre_info != 0 && now_info == 0)
	{
		//離された瞬間 = true
		just_released_information[MouseInput::Button::Middle] = true;
	}

	//現在フレームの情報を前フレーム情報として保存
	pre_button_information[MouseInput::Button::Left] = now_button_information[MouseInput::Button::Left];
	pre_button_information[MouseInput::Button::Right] = now_button_information[MouseInput::Button::Right];
	pre_button_information[MouseInput::Button::Middle] = now_button_information[MouseInput::Button::Middle];
}

//移動方向情報の更新
void MouseInput::UpdateMoveDirectionInformation()
{
	//現在マウス座標の取得
	GetMousePoint(&now_mouse_x, &now_mouse_y);

	//移動方向ベクトルの計算
	move_direction.x = now_mouse_x - base_mouse_x;
	move_direction.y = now_mouse_y - base_mouse_y;
	move_direction.z = 0.0f;

	//正規化
	move_direction.Normalized();

	//マウスの位置を基準座標に戻す
	SetMousePoint(base_mouse_x, base_mouse_y);
}

//情報の全消去
void MouseInput::ClearInformation()
{
	pre_button_information.clear();
	now_button_information.clear();
	just_pressed_information.clear();
	pressed_information.clear();
	just_released_information.clear();
}
