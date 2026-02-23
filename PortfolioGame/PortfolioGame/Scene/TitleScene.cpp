#include "TitleScene.h"
#include <memory>
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"
#include "../Input/InputSystems.h"
#include "../ResourceManager/ResourceSystems.h"

// 初期化
void TitleScene::Initialize()
{
	//初期化処理
	//必要なリソースの読み込み
	ResourceSystems::Instance().PrepareScene(scene_type);

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
}

//更新
void TitleScene::Update()
{
	//更新処理	
}


// 終了
std::unique_ptr<SceneBase> TitleScene::Terminate()
{
	//終了処理
	//リソースの解放
	ResourceSystems::Instance().ReleaseScene(scene_type);

	//シーン変更先を戻り値で返す
	return SceneFactory::Create(SceneType::Game);
}