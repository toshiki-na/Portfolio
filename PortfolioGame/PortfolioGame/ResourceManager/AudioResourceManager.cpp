#include "AudioResourceManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//読み込み
void AudioResourceManager::Load(AudioTag tag_)
{
	//既に読み込み済みなら何もしない
	if (audio_handles_list.count(tag_) > 0)
	{
		return;
	}

	//未読み込みなら読み込んで読み込み済み登録
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().audio_files_list[tag_].c_str());
	audio_handles_list.emplace(tag_, ID);
}

//削除
void AudioResourceManager::Delete(AudioTag tag_)
{
	//読み込み済みなら削除
	if (audio_handles_list.count(tag_) > 0)
	{
		auto itr = audio_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		audio_handles_list.erase(itr);
	}
}

//全削除
void AudioResourceManager::AllDelete()
{
	for (auto& ModelHandle : audio_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	audio_handles_list.clear();
}

//ハンドルの取得(エラーで-1)
int AudioResourceManager::GetHandle(AudioTag tag_) const
{
	auto itr = audio_handles_list.find(tag_);
	if (itr != audio_handles_list.end())
	{
		return (*itr).second;
	}
	return -1;
}