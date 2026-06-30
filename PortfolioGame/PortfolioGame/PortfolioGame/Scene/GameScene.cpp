#include "GameScene.h"
#include <memory>
#include <DXLib.h>

//システム系
#include "../TimeManager/TimeManager.h"
#include "../Debug/FPSCounter.h"

//ゲーム系
#include "../Constant/Tag.h"
#include "SceneManager.h"
#include "SceneFactory.h"
#include "../ResourceManager/ResourceSystemManager.h"

//初期化
void GameScene::Initialize()
{
	//時間管理オブジェクトの初期化
	TimeManager::Instance().Initialize();

	//必要なリソースの読み込み
	ResourceSystemManager::Instance().PrepareScene(scene_type);

	//カメラの初期化
	context.camera->Initialize(context.character_manager->GetPlayerTransform());

	//ライト設定
	DxLib::CreateDirLightHandle(VGet(0.0f, -1.0f, 0.0f));

	//初期化終了で更新へ移行
	SceneManager::Instance().ChangeSceneStep(SceneStep::Update);
}

//更新
void GameScene::Update()
{
	//更新処理
	//時間管理オブジェクトの更新
	TimeManager::Instance().Update();

	//FPS計測オブジェクトの更新
	FPSCounter::Instance().Update();

	//ステージの描画予約
	context.stage->Update();

	//カメラの更新
	context.camera->Update();

	//キャラクター更新
	context.character_manager->Update();

	//移動コンポーネント更新
	context.movement_system->Update();

	//アニメーションコンポーネント更新
	context.animation_system->Update();

	//衝突判定コンポーネント更新
	context.collision_system->Update();

	//描画処理
	//描画画面のクリア
	DxLib::ClearDrawScreen();

	//描画コンポーネント描画
	context.rendering_system->Draw();

	//衝突判定のデバッグ描画
	context.collision_system->DebugDraw();

	//FPSの描画
	FPSCounter::Instance().Draw();

	//描画画面と表示画面をフリップ
	DxLib::ScreenFlip();
}

//終了
std::unique_ptr<SceneBase> GameScene::Terminate()
{
	//終了処理
	//リソースの解放
	ResourceSystemManager::Instance().ReleaseScene(scene_type);

	//次シーンを返す
	//プレイヤーのHPが0ならゲームオーバーシーンへ
	if (context.character_manager->GetPlayerHP() == 0)
	{
		return SceneFactory::Create(SceneType::GameOver);
	}
	
	//プレイヤーのHPが0以外で終了するならゲームクリアシーンへ
	return SceneFactory::Create(SceneType::Clear);
}