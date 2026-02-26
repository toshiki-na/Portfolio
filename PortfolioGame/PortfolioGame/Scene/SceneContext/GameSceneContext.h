#ifndef GAMESCENE_CONTEXT_H
#define GAMESCENE_CONTEXT_H

#include <memory>
#include "../../Camera/Camera.h"
#include "../../Camera/CameraFactory.h"
#include "../../Stage/Stage.h"


class GameSceneContext
{
public:
	//コンストラクタ
	GameSceneContext()
	{
		camera = CameraFactory::Create();
	}

	//デストラクタ
	~GameSceneContext() = default;

	//カメラ
	std::unique_ptr<Camera> camera;

	//ステージ
	std::unique_ptr<Stage> stage;
};
#endif