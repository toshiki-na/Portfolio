#ifndef GAMESCENE_CONTEXT_H
#define GAMESCENE_CONTEXT_H

#include <memory>

//オブジェクト
#include "../../Camera/Camera.h"
#include "../../Camera/CameraFactory.h"
#include "../../Stage/Stage.h"
#include "../../Character/CharacterManager.h"

//コンポーネントシステム
#include "../../Component/Movement/MovementSystem.h"
#include "../../Component/Animation/AnimationSystem.h"
#include "../../Component/Render/RenderingSystem.h"



class GameSceneContext
{
public:
	//コンストラクタ
	GameSceneContext()
	{
		//カメラ生成
		camera = CameraFactory::Create();

		//コンポーネントシステム
		//移動
		movement_system = std::make_unique<MovementSystem>();

		//アニメーション
		animation_system = std::make_unique<AnimationSystem>();

		//描画
		rendering_system = std::make_unique<RenderingSystem>();

		//ステージ生成
		stage = std::make_unique<Stage>((*rendering_system));

		//キャラクターマネージャー生成
		character_manager = std::make_unique<CharacterManager>(*movement_system, *animation_system, *rendering_system);

		//プレイヤー生成
		character_manager->CreateCharacter(CharacterType::Player, camera->GetPositionFromTargetVecPtr());
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

	//アニメーション
	std::unique_ptr<AnimationSystem> animation_system;

	//描画
	std::unique_ptr<RenderingSystem> rendering_system;
};
#endif