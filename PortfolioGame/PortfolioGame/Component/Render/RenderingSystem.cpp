#include "RenderingSystem.h"

//描画コンポーネントの登録
void RenderingSystem::Register(RenderComponent* component_, ComponentLayer layer_)
{
	switch (layer_)
	{
		//プレイヤー
	case ComponentLayer::Player:
		player_render = component_;
		break;

		//敵
	case ComponentLayer::Enemy:
		enemy_renders.push_back(component_);
		break;

	default:
		break;
	}

}

//描画
void RenderingSystem::Draw()
{
	//敵の更新
	for (auto& EnemyRender : enemy_renders)
	{
		EnemyRender->Draw();
	}

	//プレイヤー更新
	player_render->Draw();

	//描画が終わったら登録された描画コンポーネントリセット
	player_render = nullptr;
	enemy_renders.clear();
}