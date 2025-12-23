#ifndef SCENEBASE_H
#define SCENEBASE_H

#include <memory>
#include "../Constant/Tag.h"

class SceneBase
{
public:
	//コンストラクタ
	SceneBase() = default;

	//デストラクタ
	virtual ~SceneBase() = default;

	//シーンの実行
	std::unique_ptr<SceneBase> Execute(SceneStep scene_step_)
	{
		//現在ステップによって分ける
		switch (scene_step_)
		{
			//初期化
		case SceneStep::Initialize:
			Initialize();
			return nullptr;
			break;

			//ループ
		case SceneStep::Update:
			Update();
			return nullptr;
			break;

			//終了
		case SceneStep::Terminate:
			return Terminate();
			break;

		default:
			return nullptr;
			break;
		}
	}

	//シーンタイプの取得
	SceneType GetSceneType() const
	{
		return scene_type;
	}

protected:
	//初期化
	virtual void Initialize() = 0;

	//ループ
	virtual void Update() = 0;

	//終了
	virtual std::unique_ptr<SceneBase> Terminate() = 0;

protected:
	//シーンタイプ
	SceneType scene_type{ SceneType::None };
};
#endif