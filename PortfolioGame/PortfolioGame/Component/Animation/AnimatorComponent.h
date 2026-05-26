#ifndef ANIMATOR_COMPONENT_H
#define ANIMATOR_COMPONENT_H

#include <memory>
#include "IAnimation.h"
#include "../State/StateComponent.h"

class AnimatorComponent
{
public:
	//コンストラクタ
	AnimatorComponent(std::unique_ptr<IAnimation> animation_):
		animation(std::move(animation_))
	{
	}

	//状態セット
	void SetStateComponennt(StateComponent* state_)
	{
		animation->SetStateComponennt(state_);
	}

	//更新
	void Update();

private:
	//アニメーション
	std::unique_ptr<IAnimation> animation;
};
#endif