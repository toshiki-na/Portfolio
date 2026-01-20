#include "ImageManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//“Ç‚İ‚İ
void ImageManager::Load(ImageTag tag_)
{
	//Šù‚É“Ç‚İ‚İÏ‚İ‚È‚ç‰½‚à‚µ‚È‚¢
	if (image_handles_list.count(tag_) > 0)
	{
		return;
	}

	//–¢“Ç‚İ‚İ‚È‚ç“Ç‚İ‚ñ‚Å“Ç‚İ‚İÏ‚İ“o˜^
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().image_files_list[tag_].c_str());
	image_handles_list.emplace(tag_, ID);
}

//íœ
void ImageManager::Delete(ImageTag tag_)
{
	//“Ç‚İ‚İÏ‚İ‚È‚çíœ
	if (image_handles_list.count(tag_) > 0)
	{
		auto itr = image_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		image_handles_list.erase(itr);
	}
}

//‘Síœ
void ImageManager::AllDelete()
{
	for (auto& ModelHandle : image_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	image_handles_list.clear();
}

//ƒnƒ“ƒhƒ‹‚Ìæ“¾
int ImageManager::GetHandle(ImageTag tag_) const
{
	if (image_handles_list.count(tag_) > 0)
	{
		auto itr = image_handles_list.find(tag_);
		return (*itr).second;
	}
	else
	{
		return -1;
	}
}