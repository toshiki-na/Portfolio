#include "GameScene.h"
#include <memory>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"
#include "../ResourceManager/ResourceSystemManager.h"
#include "../TimeManager/TimeManager.h"

//初期化
void GameScene::Initialize()
{
	//時間管理オブジェクトの初期化
	TimeManager::Instance().Initialize();

	//必要なリソースの読み込み
	ResourceSystemManager::Instance().PrepareScene(scene_type);

	//カメラの初期化
	context.camera->Initialize();

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
}

//更新
void GameScene::Update()
{
	//更新処理
	//時間管理オブジェクトの更新
	TimeManager::Instance().Update();

	//カメラの更新
	context.camera->Update();

	//キャラクター更新
	context.character_manager->Update();

	//移動コンポーネント更新
	context.movement_system->Update();

	//描画処理
	//描画画面のクリア
	DxLib::ClearDrawScreen();

	//ステージの描画
	context.stage->Draw();

	//描画コンポーネント描画
	context.rendering_system->Draw();

	//描画画面と表示画面をフリップ
	DxLib::ScreenFlip();
}

//終了
std::unique_ptr<SceneBase> GameScene::Terminate()
{
	//終了処理
	//リソースの解放
	ResourceSystemManager::Instance().ReleaseScene(scene_type);

	//シーン変更先を戻り値で返す
	return SceneFactory::Create(SceneType::Title);
}