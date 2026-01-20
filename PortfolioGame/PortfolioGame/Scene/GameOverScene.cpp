#include "GameOverScene.h"
#include <memory>
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"

//初期化
void GameOverScene::Initialize()
{
	//初期化処理

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
}

//ループ
void GameOverScene::Update()
{
	//更新処理
}

//終了
std::unique_ptr<SceneBase> GameOverScene::Terminate()
{
	//終了処理
	
	//シーン変更先を戻り値で返す
	return SceneFactory::Create(SceneType::Title);
}