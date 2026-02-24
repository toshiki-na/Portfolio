#ifndef INTERFACE_CAMERA_H
#define INTERFACE_CAMERA_H

#include "../../Utility/Vec3.h"

//カメラ操作入力インターフェース
class ICameraInput
{
public:
	//デストラクタ
	virtual ~ICameraInput() = default;

	//視点移動入力の取得
	virtual Vec3 GetLookInput() const = 0;
};
#endif