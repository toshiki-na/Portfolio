#include "ModelRenderer.h"
#include <DxLib.h>
#include "../../ResourceManager/ResourceSystemManager.h"

//ˆÊ’uî•ñƒZƒbƒg
void ModelRenderer::SetTransformComponent(TransformComponent* transform_)
{
	transform = transform_;
}

//•`‰æ
void ModelRenderer::Draw() const
{
	int handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(tag);

	//‰ñ“]Šp“x’²®
	DxLib::MV1SetRotationXYZ(handle, DxLib::VGet(0.0f, transform->GetYawRadian(), 0.0f));

	//ˆÊ’u’²®
	DxLib::MV1SetPosition(handle, transform->GetPosition().ToDXLibVECTOR());

	//•`‰æ
	DxLib::MV1DrawModel(handle);
}