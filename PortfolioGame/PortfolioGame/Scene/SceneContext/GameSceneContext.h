#ifndef GAMESCENE_CONTEXT_H
#define GAMESCENE_CONTEXT_H

#include <memory>

//オブジェクト
#include "../../Camera/Camera.h"
#include "../../Camera/CameraFactory.h"
#include "../../Stage/StageFactory.h"
#include "../../Character/CharacterManager.h"

//コンポーネントシステム
#include "../Component/Movement/MovementSystem.h"
#include "../Component/Render/RenderingSystem.h"



class GameSceneContext
{
public:
	//コンストラクタ
	GameSceneContext()
	{
		//カメラ生成
		camera = CameraFactory::Create();

		//ステージ生成
		stage = StageFactory::Create();

		//コンポーネントシステム
		//移動
		movement_system = std::make_unique<MovementSystem>();

		//描画
		rendering_system = std::make_unique<RenderingSystem>();

		//キャラクターマネージャー
		character_manager = std::make_unique<CharacterManager>(movement_system, rendering_system);

		//プレイヤー生成
		character_manager->Create(CharacterType::Player);
	}

	//デストラクタ
	~GameSceneContext() = default;

	//コピー&ムーブ禁止
	GameSceneContext(const GameSceneContext&) = delete;
	GameSceneContext& operator=(const GameSceneContext&) = delete;
	GameSceneContext(GameSceneContext&&) = delete;
	GameSceneContext& operator=(GameSceneContext&&) = delete;


	//カメラ
	std::unique_ptr<Camera> camera;

	//ステージ
	std::unique_ptr<Stage> stage;

	//キャラクターマネージャー
	std::unique_ptr<CharacterManager> character_manager;

	//コンポーネントシステム
	//移動
	std::unique_ptr<MovementSystem> movement_system;

	//描画
	std::unique_ptr<RenderingSystem> rendering_system;
};
#endif