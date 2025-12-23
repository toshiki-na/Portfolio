#include "GameScene.h"
#include <memory>
#include "SceneManager.h"
#include "SceneFactory.h"

//初期化
void GameScene::Initialize()
{
	//初期化処理
}

//更新
void GameScene::Update()
{
	//更新処理
}

//終了
std::unique_ptr<SceneBase> GameScene::Terminate()
{
	//終了処理

	//シーン変更先を戻り値で返す
	return SceneFactory::Create(SceneType::None);
}