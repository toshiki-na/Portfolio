#include "MovementComponent.h"
#include <cmath>
#include <DxLib.h>
#include "../../Constant/InitialValue.h"
#include "../../Constant/Tag.h"
#include "../../Utility/Vec3.h"
#include "../../TimeManager/TimeManager.h"
#include "../../ResourceManager/ResourceSystemManager.h"
#include "../../ResourceManager/ModelResourceManager.h"

//更新
void MovementComponent::Update()
{
	//動態計算機の入力実行と移動実行
	movement_computer->InputAction();
	movement_computer->Move();
}