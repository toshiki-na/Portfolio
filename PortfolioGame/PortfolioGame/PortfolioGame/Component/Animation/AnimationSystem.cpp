#include "AnimationSystem.h"

//アニメーションコンポーネントの登録
void AnimationSystem::Register(AnimatorComponent* component_)
{
	if (component_ != nullptr)
	{
		registered_components.push_back(component_);
	}
}

//更新
void AnimationSystem::Update()
{
	//全アニメーションコンポーネント更新
	for (auto& Component : registered_components)
	{
		Component->Update();
	}

	//更新後、登録リストクリア
	registered_components.clear();
}