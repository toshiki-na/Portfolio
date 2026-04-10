#ifndef MOUSE_CAMERA_INPUT_H
#define MOUSE_CAMERA_INPUT_H

#include "ICameraInput.h"
#include <DxLib.h>
#include "../../Input/InputSystems.h"
#include "../../Input/MouseInput.h"

class MouseCameraInput : public ICameraInput
{
public:
	//コンストラクタ
	MouseCameraInput() :
		input(InputSystems::Instance().GetMouseInput())
	{
	}

	//入力された視点移動ベクトルを取得
	Vec3 GetLookInput() const override
	{
		Vec3 result = Vec3::Zero();

		//右クリックされた瞬間にマウスカーソルを非表示
		if (input.IsHeld(MouseInput::Button::Right))
		{
			DxLib::SetMouseDispFlag(false);
		}

		//右クリック中のみ移動量を返す
		if (input.IsHeld(MouseInput::Button::Right))
		{
			result = input.GetMouseMove();
		}

		//右クリックが離されたらマウスカーソルを表示
		if (input.IsJustReleased(MouseInput::Button::Right))
		{
			DxLib::SetMouseDispFlag(true);
		}

		return result;
	}

private:
	//マウス入力
	MouseInput& input;
};
#endif