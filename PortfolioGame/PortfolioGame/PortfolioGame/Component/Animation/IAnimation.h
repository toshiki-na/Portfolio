#ifndef INTERFACE_ANIMATION_H
#define INTERFACE_ANIMATION_H

#include "../../Constant/Tag.h"
#include "../State/StateComponent.h"

class IAnimation
{
public:
	//デストラクタ
	virtual ~IAnimation() = default;

	//状態セット
	virtual void SetStateComponennt(StateComponent* state_) = 0;

	//アニメーションの変更
	virtual void Change(StateType state_) = 0;

	//更新
	virtual void Update() = 0;
};

#endif