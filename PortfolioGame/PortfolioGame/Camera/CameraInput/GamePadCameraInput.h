#pragma once
#ifndef GAMEPAD_CAMERA_INPUT_H
#define GAMEPAD_CAMERA_INPUT_H

#include "ICameraInput.h"
#include "../../Input/InputSystems.h"
#include "../../Input/GamePadInput.h"

class GamePadCameraInput : public ICameraInput
{
public:
	//コンストラクタ
	GamePadCameraInput() :
		input(InputSystems::Instance().GetGamePadInput())
	{
	}

	//デストラクタ
	~GamePadCameraInput() override = default;

	//入力された視点移動ベクトルを取得
	Vec3 GetLookInput() const override
	{
		return input.GetRightStick();
	}

private:
	GamePadInput& input;
};
#endif