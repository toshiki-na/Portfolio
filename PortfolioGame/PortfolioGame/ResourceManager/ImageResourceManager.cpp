#include "ImageResourceManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystemManager.h"

//読み込み
void ImageResourceManager::Load(ImageTag tag_)
{
	//既に読み込み済みなら何もしない
	if (image_handles_list.count(tag_) > 0)
	{
		return;
	}

	//未読み込みなら読み込んで読み込み済み登録
	int ID = DxLib::LoadGraph(ResourceSystemManager::Instance().GetResourceFiles().image_files_list[tag_].c_str());
	image_handles_list.emplace(tag_, ID);
}

//削除
void ImageResourceManager::Delete(ImageTag tag_)
{
	//読み込み済みなら削除
	auto itr = image_handles_list.find(tag_);
	if (itr != image_handles_list.end())
	{
		DxLib::DeleteGraph((*itr).second);
		image_handles_list.erase(itr);
	}
}

//全削除
void ImageResourceManager::AllDelete()
{
	for (auto& ModelHandle : image_handles_list)
	{
		DxLib::DeleteGraph(ModelHandle.second);
	}
	image_handles_list.clear();
}

//ハンドルの取得(エラーで-1)
int ImageResourceManager::GetHandle(ImageTag tag_) const
{
	auto itr = image_handles_list.find(tag_);
	if (itr != image_handles_list.end())
	{
		return (*itr).second;
	}
	return -1;
}