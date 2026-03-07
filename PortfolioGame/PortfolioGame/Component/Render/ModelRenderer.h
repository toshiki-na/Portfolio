#ifndef MODEL_RENDERER_H
#define MODEL_RENDERER_H

#include "IRenderer.h"
#include "../../Constant/Tag.h"
#include "../Transform/TransformComponent.h"
#include "../../ResourceManager/ResourceSystemManager.h"

class ModelRenderer : public IRenderer
{
public:
	//コンストラクタ
	ModelRenderer(TransformComponent& transform_, ModelTag tag_) :
		transform(transform_)
	{
		model_handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(tag_);
	}

	//描画
	void Draw() const override;

private:
	//位置座標
	TransformComponent& transform;

	//描画する3Dモデルのハンドル
	int model_handle;
};
#endif