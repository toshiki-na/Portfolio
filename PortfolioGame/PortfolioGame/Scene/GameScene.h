#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "SceneBase.h"
#include <memory>
#include "../Constant/Tag.h"

class GameScene : public SceneBase
{
public:
	//コンストラクタ
	GameScene()
	{
		//シーンタイプ設定
		scene_type = SceneType::Game;
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
};
#endif