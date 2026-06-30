#include "SceneFactory.h"
#include <memory>
#include "TitleScene.h"
#include "GameScene.h"
#include "ClearScene.h"
#include "GameOverScene.h"

//シーン生成
std::unique_ptr<SceneBase> SceneFactory::Create(SceneType scene_type_)
{
	switch (scene_type_)
	{
		//タイトルシーン
	case SceneType::Title:
		return std::make_unique<TitleScene>();
		break;

		//ゲームシーン
	case SceneType::Game:
		return std::make_unique<GameScene>();
		break;

		//クリアシーン
	case SceneType::Clear:
		return std::make_unique<ClearScene>();
		break;

		//ゲームオーバーシーン
	case SceneType::GameOver:
		return std::make_unique<GameOverScene>();
		break;

	default:
		return nullptr;
		break;
	}
}