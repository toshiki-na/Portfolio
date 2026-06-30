#include "ResourceSystemManager.h"
#include "../Constant/Tag.h"

//シーンの準備(各シーンのリソースのロード
void ResourceSystemManager::PrepareScene(SceneType scene_type_)
{
	switch (scene_type_)
	{
	case SceneType::Title:
		break;

	case SceneType::Game:
		//ステージモデルのロード
		model_manager.Load(ModelTag::Skydome);
		model_manager.Load(ModelTag::Ground);
		model_manager.Load(ModelTag::Wall);

		//プレイヤーモデルのロード
		model_manager.Load(ModelTag::Player);

		//プレイヤーアニメーションのロード
		animation_manager.Load(AnimationTag::PlayerIdle);
		animation_manager.Load(AnimationTag::PlayerMove);
		animation_manager.Load(AnimationTag::PlayerAttack01);
		animation_manager.Load(AnimationTag::PlayerAttack02);
		animation_manager.Load(AnimationTag::PlayerJump);
		animation_manager.Load(AnimationTag::PlayerAvoid);
		animation_manager.Load(AnimationTag::PlayerDead);

		//敵モデルのロード
		model_manager.Load(ModelTag::Enemy);

		//敵アニメーションのロード
		animation_manager.Load(AnimationTag::EnemyIdle);
		animation_manager.Load(AnimationTag::EnemyMove);
		animation_manager.Load(AnimationTag::EnemyAttack);
		animation_manager.Load(AnimationTag::EnemyDead);
		break;

	case SceneType::Clear:
		break;

	case SceneType::GameOver:
		break;
	}
}

//シーンの後片付け(各シーンでロードしたリソースの解放)
void ResourceSystemManager::ReleaseScene(SceneType scene_type_)
{
	switch (scene_type_)
	{
	case SceneType::Title:
		break;

	case SceneType::Game:
		//ステージモデルの解放
		model_manager.Delete(ModelTag::Skydome);
		model_manager.Delete(ModelTag::Ground);
		model_manager.Delete(ModelTag::Wall);

		//プレイヤーモデルの解放
		model_manager.Delete(ModelTag::Player);

		//プレイヤーアニメーションの解放
		animation_manager.Delete(AnimationTag::PlayerIdle);
		animation_manager.Delete(AnimationTag::PlayerMove);
		animation_manager.Delete(AnimationTag::PlayerAttack01);
		animation_manager.Delete(AnimationTag::PlayerAttack02);
		animation_manager.Delete(AnimationTag::PlayerJump);
		animation_manager.Delete(AnimationTag::PlayerAvoid);
		animation_manager.Delete(AnimationTag::PlayerDead);

		//敵モデルの解放
		model_manager.Delete(ModelTag::Enemy);

		//敵アニメーションの解放
		animation_manager.Delete(AnimationTag::EnemyIdle);
		animation_manager.Delete(AnimationTag::EnemyMove);
		animation_manager.Delete(AnimationTag::EnemyAttack);
		animation_manager.Delete(AnimationTag::EnemyDead);
		break;

	case SceneType::Clear:
		break;

	case SceneType::GameOver:
		break;
	}
}