#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

#include "SceneBase.h"
#include <memory>

class GameOverScene : public SceneBase
{
public:
	//コンストラクタ
	GameOverScene()
	{
		//シーンタイプ設定
		scene_type = SceneType::GameOver;
	}

	//デストラクタ
	~GameOverScene()override = default;

private:
	//初期化
	void Initialize() override;

	//ループ
	void Update() override;

	//終了
	std::unique_ptr<SceneBase> Terminate() override;
};
#endif