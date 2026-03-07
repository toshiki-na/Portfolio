#ifndef MODEL_RENDER_COMPONENT_H
#define MODEL_RENDER_COMPONENT_H

#include <memory>
#include "IRenderer.h"

class RenderComponent
{
public:
	//コンストラクタ
	RenderComponent(std::unique_ptr<IRenderer> renderer_) :
		renderer(std::move(renderer_))
	{ 
	}

	//描画
	void Draw();

private:
	//描画システム
	std::unique_ptr<IRenderer> renderer;
};
#endif