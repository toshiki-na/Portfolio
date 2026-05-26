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

	//’n–Ê‚ÌŠg‘å
	if (tag == ModelTag::Ground)
	{
		DxLib::MV1SetScale(handle, VGet(2.0f, 1.0f, 3.5f));
	}

	//‰ñ“]Šp“x’²®
	DxLib::MV1SetRotationXYZ(handle, DxLib::VGet(0.0f, transform->GetYawRadian(), 0.0f));

	//ˆÊ’u’²®
	DxLib::MV1SetPosition(handle, transform->GetPosition().ToDXLibVECTOR());

	//•`‰æ
	DxLib::MV1DrawModel(handle);
}