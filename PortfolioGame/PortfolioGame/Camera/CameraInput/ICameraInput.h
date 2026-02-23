#ifndef INTERFACE_CAMERA_H
#define INTERFACE_CAMERA_H

#include "../../Utility/Vec3.h"

//カメラ操作入力インターフェース
class ICameraInput
{
public:
	//デストラクタ
	virtual ~ICameraInput() = default;

	//入力された視点移動ベクトルを取得
	virtual Vec3 GetLookInput() const = 0;
};
#endif