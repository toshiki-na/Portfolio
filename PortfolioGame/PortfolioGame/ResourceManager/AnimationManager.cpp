#include "AnimationManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//“Ç‚Ýž‚Ý
void AnimationManager::Load(AnimationTag tag_)
{
	//Šù‚É“Ç‚Ýž‚ÝÏ‚Ý‚È‚ç‰½‚à‚µ‚È‚¢
	if (animation_handles_list.count(tag_) > 0)
	{
		return;
	}

	//–¢“Ç‚Ýž‚Ý‚È‚ç“Ç‚Ýž‚ñ‚Å“Ç‚Ýž‚ÝÏ‚Ý“o˜^
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().animation_files_list[tag_].c_str());
	animation_handles_list.emplace(tag_, ID);
}

//íœ
void AnimationManager::Delete(AnimationTag tag_)
{
	//“Ç‚Ýž‚ÝÏ‚Ý‚È‚çíœ
	if (animation_handles_list.count(tag_) > 0)
	{
		auto itr = animation_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		animation_handles_list.erase(itr);
	}
}

//‘Síœ
void AnimationManager::AllDelete()
{
	for (auto& ModelHandle : animation_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	animation_handles_list.clear();
}

//ƒnƒ“ƒhƒ‹‚ÌŽæ“¾
int AnimationManager::GetHandle(AnimationTag tag_) const
{
	if (animation_handles_list.count(tag_) > 0)
	{
		auto itr = animation_handles_list.find(tag_);
		return (*itr).second;
	}
	else
	{
		return -1;
	}
}