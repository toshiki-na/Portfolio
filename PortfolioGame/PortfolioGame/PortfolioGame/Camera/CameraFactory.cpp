#include "CameraFactory.h"
#include "../Input/InputSystems.h"
#include "CameraInput/MouseCameraInput.h"
#include "CameraInput/GamePadCameraInput.h"

//カメラ生成
std::unique_ptr<Camera> CameraFactory::Create()
{
	//入力受付システム確認
	InputSystems& input_system = InputSystems::Instance();

	//ゲームパッド
	if (input_system.GetGamePadInput().GetConnectedGamePadCount() > 0)
	{
		return std::make_unique<Camera>(std::make_unique<GamePadCameraInput>());
	}
	
	//マウス
	return std::make_unique<Camera>(std::make_unique<MouseCameraInput>());
}