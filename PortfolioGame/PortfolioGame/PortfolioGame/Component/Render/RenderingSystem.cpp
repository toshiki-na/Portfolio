#include "RenderingSystem.h"

//描画コンポーネントの登録
void RenderingSystem::Register(RenderComponent* component_)
{
	switch (component_->GetLayer())
	{
		//プレイヤー
	case ComponentLayer::Player:
		player_render = component_;
		break;

		//敵
	case ComponentLayer::Enemy:
		enemy_renders.push_back(component_);
		break;

		//ステージ
	case ComponentLayer::Stage:
		stage_renders.push_back(component_);
		break;

		//例外
	default:
		break;
	}
}

//描画
void RenderingSystem::Draw()
{
	//ステージ描画
	for (auto& StageRender : stage_renders)
	{
		StageRender->Draw();
	}

	//敵の描画
	for (auto& EnemyRender : enemy_renders)
	{
		EnemyRender->Draw();
	}

	//プレイヤー描画
	if (player_render != nullptr)
	{
		player_render->Draw();
	}

	//描画が終わったら登録された描画コンポーネントリセット
	player_render = nullptr;
	enemy_renders.clear();
	stage_renders.clear();
}