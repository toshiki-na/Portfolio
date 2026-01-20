#include "GameScene.h"
#include <memory>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"
#include "../ResourceManager/ResourceSystems.h"

//初期化
void GameScene::Initialize()
{
	//3Dモデルの読み込み
	//プレイヤーの読み込み
	ResourceSystems::Instance().GetModelManager().Load(ModelTag::Player);
	//初期化処理

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
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
	return SceneFactory::Create(SceneType::Title);
}