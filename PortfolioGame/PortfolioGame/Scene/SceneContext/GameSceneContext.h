#ifndef GAMESCENE_CONTEXT_H
#define GAMESCENE_CONTEXT_H

#include <memory>
#include "../../Camera/Camera.h"
#include "../../Camera/CameraFactory.h"
#include "../../Stage/StageFactory.h"


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
	}

	//カメラ
	std::unique_ptr<Camera> camera;

	//ステージ
	std::unique_ptr<Stage> stage;
};
#endif