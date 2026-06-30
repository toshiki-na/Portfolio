#ifndef ANIMATION_SYSTEM_H
#define ANIMATION_SYSTEM_H

#include <vector>
#include "AnimatorComponent.h"

class AnimationSystem
{
public:
	//コンストラクタ
	AnimationSystem() = default;

	//デストラクタ
	~AnimationSystem() = default;

	//コピー&ムーブ禁止
	AnimationSystem(const AnimationSystem&) = delete;
	AnimationSystem& operator=(const AnimationSystem&) = delete;
	AnimationSystem(AnimationSystem&&) = delete;
	AnimationSystem& operator=(AnimationSystem&&) = delete;

	//アニメーションコンポーネントの登録
	void Register(AnimatorComponent* component_);

	//更新
	void Update();

private:
	//登録されたアニメーションコンポーネント
	std::vector<AnimatorComponent*> registered_components;
};
#endif