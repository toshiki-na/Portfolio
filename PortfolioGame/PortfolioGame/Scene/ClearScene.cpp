#include "ClearScene.h"
#include <memory>
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"

// 初期化
void ClearScene::Initialize()
{
	//初期化処理

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
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