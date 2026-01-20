#include "ModelManager.h"
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceFiles.h"

//“Ç‚İ‚İ
void ModelManager::Load(ModelTag tag_)
{
	int ID = MV1LoadModel(ResourceFiles::model_files_pass_list[tag_]);
}

//íœ
void ModelManager::Delete(ModelTag tag_)
{
}

//‘Síœ
void ModelManager::AllDelete()
{
	for (auto& ModelHandles : model_handles_list)
	{
	}
}

//ƒnƒ“ƒhƒ‹‚Ìæ“¾
int ModelManager::GetHandle(ModelTag tag_)
{
	return model_handles_list[tag_];
}