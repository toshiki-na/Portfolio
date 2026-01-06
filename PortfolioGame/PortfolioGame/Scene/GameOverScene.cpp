#include "GameOverScene.h"
#include <memory>
#include "SceneManager.h"
#include "SceneFactory.h"

//初期化
void GameOverScene::Initialize()
{
	//初期化処理
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