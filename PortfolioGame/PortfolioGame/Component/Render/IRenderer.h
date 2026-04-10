#ifndef INTERFACE_RENDERER_H
#define INTERFACE_RENDERER_H

#include "../Transform/TransformComponent.h"

class IRenderer
{
public:
	//デストラクタ
	virtual ~IRenderer() = default;

	//位置情報セット
	virtual void SetTransformComponent(TransformComponent* transform_) = 0;

	//描画
	virtual void Draw() const = 0;
};
#endif