#ifndef STAGE_OBJECT_BASE_H
#define STAGE_OBJECT_BASE_H

#include <memory>
#include "../../Component/Transform/TransformComponent.h"
#include "../../Component/Render/RenderComponent.h"

//ステージオブジェクトインターフェース
class StageObjectBase
{
public:
	//コンストラクタ
	StageObjectBase(TransformComponent& transform_, RenderComponent& render_):
		transform(std::move(transform_)),
		render(std::move(render_))
	{
		//位置情報参照先セット
		render.SetTransformComponent(&transform);
	}

	//デストラクタ
	virtual ~StageObjectBase() = default;

	//位置座標コンポーネント取得
	TransformComponent* GetTransform()
	{
		return &transform;
	}

	//描画コンポーネント取得
	RenderComponent* GetRender()
	{
		return &render;
	}

protected:
	//位置座標コンポーネント
	TransformComponent transform;

	//描画コンポーネント
	RenderComponent render;
};
#endif