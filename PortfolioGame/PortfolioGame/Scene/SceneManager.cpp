#include "SceneManager.h"
#include "SceneFactory.h"

//シーンの実行
void SceneManager::Execute()
{
	//現在シーンの現在ステップを実行
	std::unique_ptr<SceneBase> execute_result = current_scene->Execute(current_scene_step);

	//シーン変更先がある場合、シーンを変更
	if (execute_result != nullptr)
	{
		current_scene = std::move(execute_result);

		//初期ステップに変更
		current_scene_step = SceneStep::Initialize;
	}
}

//シーンステップの変更
void SceneManager::ChangeSceneStep(SceneStep next_scene_step_)
{
	current_scene_step = next_scene_step_;
}