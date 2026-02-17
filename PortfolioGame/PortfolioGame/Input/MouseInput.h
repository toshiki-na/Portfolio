#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H

#include <unordered_map>
#include "../Constant/ConstantValue.h"
#include "../Utility/Vec3.h"

class MouseInput
{
public:
	MouseInput() = default;
	~MouseInput() = default;

public:
	//マウスのボタンの種類
	enum class Button
	{
		Left,
		Right,
		Middle
	};

public:
	//更新(毎フレーム処理の前に呼ぶ)
	void Update();

	//押されたフレームかどうかの取得
	bool IsJustPressed(MouseInput::Button button_) const;

	//押され続けているフレームかどうかの取得
	bool IsPressed(MouseInput::Button button_) const;

	//離されたフレームかどうかの取得
	bool IsJustReleased(MouseInput::Button button_) const;

	//マウスの移動方向の取得(zは常に0.0f)
	Vec3 GetMouseMoveDirection() const;

private:
	//情報の初期化
	void InitializeInformation();

	//前フレームの押下情報をリセット
	void ResetPressInformation();

	//押下情報の更新
	void UpdatePressInformation();

	//移動方向情報の更新
	void UpdateMoveDirectionInformation();

	//情報の全消去
	void ClearInformation();

private:
	//マウスの入力情報関連
	//前フレーム
	std::unordered_map<MouseInput::Button, int> pre_button_information;

	//現在フレーム
	std::unordered_map<MouseInput::Button, int> now_button_information;

	//押されたフレームかどうか
	std::unordered_map<MouseInput::Button, bool>just_pressed_information;

	//押され続けているフレームかどうか
	std::unordered_map<MouseInput::Button, bool> pressed_information;

	//離されたフレームかどうか
	std::unordered_map<MouseInput::Button, bool> just_released_information;

	//マウス移動方向情報関連
	//マウスの移動方向ベクトル
	Vec3 move_direction{ 0.0f, 0.0f, 0.0f };

	//画面中央をマウスの基準座標とする
	//X座標
	const int base_mouse_x{ static_cast<int>(SCREEN_WIDTH) / 2 };
	//Y座標
	const int base_mouse_y{ static_cast<int>(SCREEN_HEIGHT) / 2 };

	//現在マウス座標
	//X座標
	int now_mouse_x{ 0 };
	//Y座標
	int now_mouse_y{ 0 };
};
#endif