#ifndef MODEL_RENDER_COMPONENT_H
#define MODEL_RENDER_COMPONENT_H

#include <memory>
#include "IRenderer.h"
#include "../Transform/TransformComponent.h"

class RenderComponent
{
public:
	//コンストラクタ
	RenderComponent(std::unique_ptr<IRenderer> renderer_) :
		renderer(std::move(renderer_))
	{ 
	}

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_);

	//描画
	void Draw();

private:
	//描画システム
	std::unique_ptr<IRenderer> renderer;
};
#endif