#include "StageObjectFactory.h"
#include <memory>

//初期値定数
#include "../Constant/InitialValue.h"

//タグ
#include "../Constant/Tag.h"

//ステージオブジェクト
#include "StageObject/StageObjectBase.h"
#include "StageObject/Skydome.h"
#include "StageObject/Ground.h"
#include "StageObject/Wall.h"

//位置情報コンポーネント
#include "../Component/Transform/TransformComponent.h"

//描画コンポーネント
#include "../Component/Render/RenderComponent.h"
#include "../Component/Render/ModelRenderer.h"

//ステージオブジェクト生成
std::unique_ptr<StageObjectBase> StageObjectFactory::Create(StageObjectType type_)
{

	//各オブジェクト生成
	switch (type_)
	{
		//空
	case StageObjectType::SkyDome:
	{
		//位置座標コンポーネント生成
		TransformComponent transform;

		//描画機作成
		std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Skydome);

		//描画コンポーネント生成
		RenderComponent render(std::move(renderer), ComponentLayer::Stage);

		//空を生成して返す
		return std::make_unique<Skydome>(transform, render);
	}

		//地面
	case StageObjectType::Ground:
	{
		//位置座標コンポーネント生成
		TransformComponent transform = TransformComponent(Vec3::Zero(), Vec3::Zero(), 0.0f, Vec3{ 2.0f, 1.0f, 3.5f });

		//描画機作成
		std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Ground);

		//描画コンポーネント生成
		RenderComponent render(std::move(renderer), ComponentLayer::Stage);

		//地面を生成して返す
		return std::make_unique<Skydome>(transform, render);
	}

		//壁
	case StageObjectType::Wall:
	{
		//位置座標コンポーネント生成
		TransformComponent transform;

		//描画機作成
		std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Wall);

		//描画コンポーネント生成
		RenderComponent render(std::move(renderer), ComponentLayer::Stage);

		//壁を生成して返す
		return std::make_unique<Skydome>(transform, render);
	}

	//指定外オブジェクトの場合nullptrを返す
	default:
		return nullptr;
	}
}