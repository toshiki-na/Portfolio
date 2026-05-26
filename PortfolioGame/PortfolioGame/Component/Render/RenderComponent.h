#ifndef MODEL_RENDER_COMPONENT_H
#define MODEL_RENDER_COMPONENT_H

#include <memory>
#include "../../Constant/Tag.h"
#include "IRenderer.h"
#include "../Transform/TransformComponent.h"

class RenderComponent
{
public:
	//コンストラクタ
	RenderComponent(std::unique_ptr<IRenderer> renderer_, ComponentLayer layer_) :
		renderer(std::move(renderer_)),
		layer(layer_)
	{ 
	}

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_);

	//コンポーネントレイヤー取得
	ComponentLayer GetLayer() const
	{
		return layer;
	}

	//描画
	void Draw();

private:
	//コンポーネントレイヤー
	ComponentLayer layer;

	//描画システム
	std::unique_ptr<IRenderer> renderer;
};
#endif