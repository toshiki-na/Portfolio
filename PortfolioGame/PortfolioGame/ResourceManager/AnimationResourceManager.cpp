#include "AnimationResourceManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//読み込み
void AnimationResourceManager::Load(AnimationTag tag_)
{
	//既に読み込み済みなら何もしない
	if (animation_handles_list.count(tag_) > 0)
	{
		return;
	}

	//未読み込みなら読み込んで読み込み済み登録
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().animation_files_list[tag_].c_str());
	animation_handles_list.emplace(tag_, ID);
}

//削除
void AnimationResourceManager::Delete(AnimationTag tag_)
{
	//読み込み済みなら削除
	if (animation_handles_list.count(tag_) > 0)
	{
		auto itr = animation_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		animation_handles_list.erase(itr);
	}
}

//全削除
void AnimationResourceManager::AllDelete()
{
	for (auto& ModelHandle : animation_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	animation_handles_list.clear();
}

//ハンドルの取得(エラーで-1)
int AnimationResourceManager::GetHandle(AnimationTag tag_) const
{
	auto itr = animation_handles_list.find(tag_);
	if (itr != animation_handles_list.end())
	{
		return (*itr).second;
	}
	return -1;
}