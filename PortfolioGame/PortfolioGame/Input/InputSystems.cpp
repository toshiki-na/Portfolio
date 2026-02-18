#include "InputSystems.h"
#include "MouseInput.h"
#include "KeyBordInput.h"
#include "GamePadInput.h"

//毎フレームの開始時に実行
void InputSystems::BeginFrame()
{
	mouse->BeginFrame();
}

//毎フレームの終了時に実行
void InputSystems::EndFrame()
{
}