#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "IRenderer.h"
#include "../../Constant/Tag.h"
#include "../Transform/TransformComponent.h"

class ModelRenderer : public IRenderer
{
public:
	//コンストラクタ
	ModelRenderer(ModelTag tag_) :
		tag(tag_)
	{
	}

	//位置情報セット
	void SetTransformComponent(TransformComponent* transform_) override;

	//描画
	void Draw() const override;

private:
	//位置座標
	TransformComponent* transform{ nullptr };

	//モデルタグ
	ModelTag tag;
};
#endif