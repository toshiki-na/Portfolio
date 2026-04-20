#include "StageContext.h"
#include "../../Component/Transform/TransformComponent.h"
#include "../../Constant/Tag.h"
#include "../StageObjectFactory.h"

//ステージ生成
void StageContext::CreateStage(int stage_level_)
{
	//現状のステージ破棄
	stage_objects.clear();

	switch (stage_level_)
	{
		//チュートリアルステージ
	case 0:
		break;

		//Level1
	case 1:
		//サイズを事前確保
		stage_objects.reserve(3);
		//空
		stage_objects.push_back(StageObjectFactory::Create(StageObjectType::SkyDome));
		//地面
		stage_objects.push_back(StageObjectFactory::Create(StageObjectType::Ground));
		//壁
		stage_objects.push_back(StageObjectFactory::Create(StageObjectType::Wall));
		break;

		//以降なし(追加するならこの後に追加)
	default:
		break;
	}
}