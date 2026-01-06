#include "ClearScene.h"
#include <memory>
#include "SceneManager.h"
#include "SceneFactory.h"

// 初期化
void ClearScene::Initialize()
{
	//初期化処理
}

// ループ
void ClearScene::Update()
{
	//更新処理
}


// 終了
std::unique_ptr<SceneBase> ClearScene::Terminate()
{
	//終了処理

	//シーン変更先を戻り値で返す
	return SceneFactory::Create(SceneType::Title);
}