#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SceneBase.h"
#include <memory>
#include "../Constant/Tag.h"

//ゲームシーンで用いるオブジェクト
#include "../Camera/Camera.h"
#include "../Stage/Stage.h"

class GameScene : public SceneBase
{
public:
	//コンストラクタ
	GameScene()
	{
		//シーンタイプ設定
		scene_type = SceneType::Game;

		//ゲームシーンで用いるオブジェクトを生成
		//カメラ
		camera = std::make_unique<Camera>();

		//ステージ
		stage = std::make_unique<Stage>();
	}

	//デストラクタ
	~GameScene()override = default;

private:
	//初期化
	void Initialize() override;

	//ループ
	void Update() override;

	//終了
	std::unique_ptr<SceneBase> Terminate() override;

private:
	//ゲームシーンで用いるオブジェクト
	//カメラ
	std::unique_ptr<Camera> camera;

	//ステージ
	std::unique_ptr<Stage> stage;
};
#endif