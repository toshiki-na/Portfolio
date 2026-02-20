#include "ModelResourceManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//読み込み
void ModelResourceManager::Load(ModelTag tag_)
{
	//既に読み込み済みなら何もしない
	if (model_handles_list.count(tag_) >0)
	{
		return;
	}
	
	//未読み込みなら読み込んで読み込み済み登録
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().model_files_list[tag_].c_str());
	model_handles_list.emplace(tag_, ID);
}

//削除
void ModelResourceManager::Delete(ModelTag tag_)
{
	//読み込み済みなら削除
	if (model_handles_list.count(tag_) > 0)
	{
		auto itr = model_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		model_handles_list.erase(itr);
	}
}

//全削除
void ModelResourceManager::AllDelete()
{
	for (auto& ModelHandle : model_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	model_handles_list.clear();
}

//ハンドルの取得(エラーで-1)
int ModelResourceManager::GetHandle(ModelTag tag_) const
{
	auto itr = model_handles_list.find(tag_);
	if (itr != model_handles_list.end())
	{
		return (*itr).second;
	}
	return -1;
}