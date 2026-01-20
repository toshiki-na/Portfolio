#include "AudioManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//“Ç‚İ‚İ
void AudioManager::Load(AudioTag tag_)
{
	//Šù‚É“Ç‚İ‚İÏ‚İ‚È‚ç‰½‚à‚µ‚È‚¢
	if (audio_handles_list.count(tag_) > 0)
	{
		return;
	}

	//–¢“Ç‚İ‚İ‚È‚ç“Ç‚İ‚ñ‚Å“Ç‚İ‚İÏ‚İ“o˜^
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().audio_files_list[tag_].c_str());
	audio_handles_list.emplace(tag_, ID);
}

//íœ
void AudioManager::Delete(AudioTag tag_)
{
	//“Ç‚İ‚İÏ‚İ‚È‚çíœ
	if (audio_handles_list.count(tag_) > 0)
	{
		auto itr = audio_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		audio_handles_list.erase(itr);
	}
}

//‘Síœ
void AudioManager::AllDelete()
{
	for (auto& ModelHandle : audio_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	audio_handles_list.clear();
}

//ƒnƒ“ƒhƒ‹‚Ìæ“¾
int AudioManager::GetHandle(AudioTag tag_) const
{
	if (audio_handles_list.count(tag_) > 0)
	{
		auto itr = audio_handles_list.find(tag_);
		return (*itr).second;
	}
	else
	{
		return -1;
	}
}