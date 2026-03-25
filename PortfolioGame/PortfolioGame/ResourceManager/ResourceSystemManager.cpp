#include "ResourceSystemManager.h"
#include "../Constant/Tag.h"

//シーンの準備(各シーンのリソースのロード
void ResourceSystemManager::PrepareScene(SceneType scene_type_)
{
	switch (scene_type_)
	{
	case SceneType::Title:
		break;

	case SceneType::Game:
		//ステージのロード
		model_manager.Load(ModelTag::Skydome);
		model_manager.Load(ModelTag::Ground);
		model_manager.Load(ModelTag::Wall);

		//プレイヤーのロード
		model_manager.Load(ModelTag::Player);
		break;

	case SceneType::Clear:
		break;

	case SceneType::GameOver:
		break;
	}
}

//シーンの後片付け(各シーンでロードしたリソースの解放)
void ResourceSystemManager::ReleaseScene(SceneType scene_type_)
{
	switch (scene_type_)
	{
	case SceneType::Title:
		break;

	case SceneType::Game:
		//ステージリソースの解放
		model_manager.Delete(ModelTag::Skydome);
		model_manager.Delete(ModelTag::Ground);
		model_manager.Delete(ModelTag::Wall);

		//プレイヤーリソースの解放
		model_manager.Delete(ModelTag::Player);
		break;

	case SceneType::Clear:
		break;

	case SceneType::GameOver:
		break;
	}
}