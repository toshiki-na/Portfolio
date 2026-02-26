#include "CameraFactory.h"
#include "../Input/InputSystems.h"
#include "CameraInput/MouseCameraInput.h"
#include "CameraInput/GamePadCameraInput.h"

//ƒJƒƒ‰¶¬
std::unique_ptr<Camera> CameraFactory::Create()
{
	InputSystems& input_system = InputSystems::Instance();

	if (input_system.GetGamePadInput().GetConnectedGamePadCount() > 0)
	{
		return std::make_unique<Camera>(std::make_unique<GamePadCameraInput>());
	}
	
	return std::make_unique<Camera>(std::make_unique<MouseCameraInput>());
}