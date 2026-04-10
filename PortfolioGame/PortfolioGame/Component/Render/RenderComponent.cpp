#include "RenderComponent.h"

//位置情報セット
void RenderComponent::SetTransformComponent(TransformComponent* transform_)
{
	renderer->SetTransformComponent(transform_);
}

//描画
void RenderComponent::Draw()
{
	renderer->Draw();
}