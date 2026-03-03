#ifndef INTERFACE_MOVE_VECTOR_COMPUTER_H
#define INTERFACE_MOVE_VECTOR_COMPUTER_H

#include "../../Utility/Vec3.h"

class IMoveVectorComputer
{
public:
	//デストラクタ
	virtual ~IMoveVectorComputer() = default;

	//移動方向の取得
	virtual Vec3 GetVector() = 0;
};
#endif