#ifndef SCENEMANAGERR_H
#define SCENEMANAGERR_H

#include <memory>
#include "../Constant/Tag.h"
#include "SceneBase.h"
#include "SceneFactory.h"

class SceneManager
{
//シングルトンオブジェクト*******************************
public:
	//唯一のインスタンスの取得
	static SceneManager* Instance()
	{
		static SceneManager instance;
		return &instance;
	}

	//コピー&ムーブ禁止
	SceneManager(const SceneManager&) = delete;
	SceneManager& operator=(const SceneManager&) = delete;
	SceneManager(SceneManager&&) = delete;
	SceneManager& operator=(SceneManager&&) = delete;

private:
	//コンストラクタ
	SceneManager()
	{
		//初期シーンの生成
		current_scene = SceneFactory::Create(SceneType::Title);

		//初期シーンステップを初期化に変更
		current_scene_step = SceneStep::Initialize;
	}

	//デストラクタ
	~SceneManager() = default;
//*********************************************************

public:
	//シーンの実行
	void Execute();

	//シーンステップの変更
	void ChangeSceneStep(SceneStep next_scene_step_);

private:
	//現在シーン
	std::unique_ptr<SceneBase> current_scene;

	//現在シーンステップ
	SceneStep current_scene_step{ SceneStep::Initialize };
};
#endif