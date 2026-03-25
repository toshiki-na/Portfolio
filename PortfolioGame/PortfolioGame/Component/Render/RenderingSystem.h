#ifndef RENDERING_SYSTEM_H
#define RENDERING_SYSTEM_H

#include <vector>
#include "RenderComponent.h"
#include "../../Constant/Tag.h"

class RenderingSystem
{
public:
	//コンストラクタ
	RenderingSystem() = default;

	//コピー&ムーブ禁止
	RenderingSystem(const RenderingSystem&) = delete;
	RenderingSystem& operator=(const RenderingSystem&) = delete;
	RenderingSystem(RenderingSystem&&) = delete;
	RenderingSystem& operator=(RenderingSystem&&) = delete;

	//描画コンポーネントの登録
	void Register(RenderComponent* component_, ComponentLayer layer_);

	//描画
	void Draw();

private:
	//登録された描画コンポーネント
	//プレイヤー
	RenderComponent* player_render;

	//敵
	std::vector<RenderComponent*> enemy_renders;
};
#endif