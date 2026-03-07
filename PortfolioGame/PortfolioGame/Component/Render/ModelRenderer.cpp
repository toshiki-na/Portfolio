#include "ModelRenderer.h"
#include <DxLib.h>

//ï`âÊ
void ModelRenderer::Draw() const
{
	//âÒì]äpìxí≤êÆ
	DxLib::MV1SetRotationXYZ(model_handle, DxLib::VGet(0.0f, transform.GetYawRadian(), 0.0f));

	//à íuí≤êÆ
	DxLib::MV1SetPosition(model_handle, transform.GetPosition().ToDXLibVECTOR());

	//ï`âÊ
	DxLib::MV1DrawModel(model_handle);
}