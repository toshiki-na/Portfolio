#include "ModelManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystems.h"

//“Ç‚Ýž‚Ý
void ModelManager::Load(ModelTag tag_)
{
	//Šù‚É“Ç‚Ýž‚ÝÏ‚Ý‚È‚ç‰½‚à‚µ‚È‚¢
	if (model_handles_list.count(tag_) >0)
	{
		return;
	}
	
	//–¢“Ç‚Ýž‚Ý‚È‚ç“Ç‚Ýž‚ñ‚Å“Ç‚Ýž‚ÝÏ‚Ý“o˜^
	int ID = MV1LoadModel(ResourceSystems::Instance().GetResourceFiles().model_files_list[tag_].c_str());
	model_handles_list.emplace(tag_, ID);
}

//íœ
void ModelManager::Delete(ModelTag tag_)
{
	//“Ç‚Ýž‚ÝÏ‚Ý‚È‚çíœ
	if (model_handles_list.count(tag_) > 0)
	{
		auto itr = model_handles_list.find(tag_);
		MV1DeleteModel((*itr).second);
		model_handles_list.erase(itr);
	}
}

//‘Síœ
void ModelManager::AllDelete()
{
	for (auto& ModelHandle : model_handles_list)
	{
		MV1DeleteModel(ModelHandle.second);
	}
	model_handles_list.clear();
}

//ƒnƒ“ƒhƒ‹‚ÌŽæ“¾
int ModelManager::GetHandle(ModelTag tag_) const
{
	if (model_handles_list.count(tag_) > 0)
	{
		auto itr = model_handles_list.find(tag_);
		return (*itr).second;
	}
	else
	{
		return -1;
	}
}