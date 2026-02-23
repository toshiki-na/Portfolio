#ifndef MOUSE_CAMERA_INPUT_H
#define MOUSE_CAMERA_INPUT_H

#include "ICameraInput.h"
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

	//デストラクタ
	~MouseCameraInput() = default;

	//入力された視点移動ベクトルを取得
	Vec3 GetLookInput() const override
	{
		Vec3 result = Vec3::Zero();

		//左クリック中のみ移動量を返す
		if (input.IsHeld(MouseInput::Button::Left))
		{
			result = input.GetMouseMove();
		}

		return result;
	}

private:
	MouseInput& input;
};
#endif