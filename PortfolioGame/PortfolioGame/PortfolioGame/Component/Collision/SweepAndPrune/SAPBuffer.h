#ifndef SAP_BUFFER_H
#define SAP_BUFFER_H

#include "../../../Utility/Vec3.h"
#include "../ColliderComponent.h"

struct SAPBuffer
{
public:
	//コンストラクタ
	SAPBuffer(ColliderComponent* component_):
		component(component_)
	{
		//最小頂点、最大頂点を設定
		Vec3 collider_position = component_->GetBroadCollider().positon;
		Vec3 collider_scale = component_->GetBroadCollider().scale;
		min_vertex = collider_position - (collider_scale * 0.5f);
		max_vertex = collider_position + (collider_scale * 0.5f);
	}

	//最小頂点
	Vec3 min_vertex;

	//最大頂点
	Vec3 max_vertex;

	//衝突判定コンポーネント
	ColliderComponent* component;
};
#endif