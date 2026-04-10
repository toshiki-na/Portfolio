#include "CharacterFactory.h"
#include <memory>

//タグ
#include "../Constant/Tag.h"

//キャラクター
#include "CharacterBase.h"
#include "Player/Player.h"

//位置情報コンポーネント
#include "../Component/Transform/TransformComponent.h"

//移動コンポーネント
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Movement/Player/PlayerMoveVectorComputer.h"

//描画コンポーネント
#include "../Component/Render/RenderComponent.h"
#include "../Component/Render/ModelRenderer.h"

//入力情報
#include "../Input/InputSystems.h"
#include "Player/PlayerInput/KeyBoardAndMousePlayerInput.h"
#include "Player/PlayerInput/GamePadPlayerInput.h"

//キャラクター生成
std::unique_ptr<CharacterBase> CharacterFactory::Create(CharacterType type_)
{
	switch (type_)
	{
		//プレイヤー生成
	case CharacterType::Player:
		return CreatePlayer();

		//敵生成
	case CharacterType::Enemy:
		return CreateEnemy();

	default:
		return nullptr;
	}
}

//プレイヤー生成
std::unique_ptr<CharacterBase> CharacterFactory::CreatePlayer()
{
	//初期位置
	Vec3 init_position = Vec3::Zero();

	//初期前方向ベクトル
	Vec3 init_forward = Vec3(0.0f, 0.0f, -1.0f);

	//初期Y軸回転角度
	float init_yaw_radian = 0.0f;

	//位置座標コンポーネント生成
	TransformComponent transform(init_position, init_forward, init_yaw_radian);

	//入力をキーボード&マウスかゲームパッドか確認して生成
	std::unique_ptr<IPlayerInput> input;
	if (InputSystems::Instance().GetGamePadInput().GetConnectedGamePadCount() > 0)
	{
		//ゲームパッド
		input = std::make_unique<GamePadPlayerInput>();
	}
	else
	{
		//キーボード&マウス
		input = std::make_unique<KeyBoardAndMousePlayerInput>();
	}

	//移動方向計算機作成
	std::unique_ptr<IMoveVectorComputer> move_vec_compurter = std::make_unique<PlayerMoveVectorComputer>(std::move(input));

	//移動コンポーネント作成
	MovementComponent movement(std::move(move_vec_compurter));

	//描画機作成
	std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Player);

	//描画コンポーネント生成
	RenderComponent render(std::move(renderer));

	//プレイヤー生成して返す
	return std::make_unique<Player>(transform, movement, render);
}

//敵生成
std::unique_ptr<CharacterBase> CharacterFactory::CreateEnemy()
{
	//後で実装*****
	return nullptr;
	//*************
}
