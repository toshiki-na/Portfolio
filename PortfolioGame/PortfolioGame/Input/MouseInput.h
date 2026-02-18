#ifndef MOUSE_INPUT_H
#define MOUSE_INPUT_H

#include <DxLib.h>
#include "../Constant/ConstantValue.h"
#include "../Utility/Vec3.h"

class MouseInput
{
public:
	//コンストラクタ
	MouseInput()
	{
		//マウスの位置を基準座標に置く
		DxLib::SetMousePoint(base_x, base_y);
	}

	//デストラクタ
	~MouseInput() = default;

public:
	//マウスのボタンの種類
	enum class Button
	{
		Left,
		Right,
		Middle,
	};

public:
	//毎フレームの最初に実行
	void BeginFrame();

	//毎フレームの最後に実行
	void EndFrame();

	//押されたフレームかどうかの取得
	bool IsJustPressed(MouseInput::Button button_) const;

	//押され続けているフレームかどうかの取得
	bool IsHeld(MouseInput::Button button_) const;

	//離されたフレームかどうかの取得
	bool IsJustReleased(MouseInput::Button button_) const;

	//マウスの移動方向の取得(zは常に0.0f)
	Vec3 GetMouseMoveDirection() const;

private:
	//各ボタンのDXライブラリのビットマスク値を取得
	int ToDxLibMask(Button button_) const;

private:
	//マウスの入力状態
	//前フレーム
	int pre_button_state{ 0 };

	//現在フレーム
	int now_button_state{ 0 };

	//マウス移動方向情報関連
	//マウスの移動方向ベクトル
	Vec3 move_direction{ 0.0f, 0.0f, 0.0f };

	//画面中央をマウスの基準座標とする
	//X座標
	const int base_x{ static_cast<int>(SCREEN_WIDTH) / 2 };
	//Y座標
	const int base_y{ static_cast<int>(SCREEN_HEIGHT) / 2 };

	//現在マウス座標
	//X座標
	int now_x{ 0 };
	//Y座標
	int now_y{ 0 };
};
#endif