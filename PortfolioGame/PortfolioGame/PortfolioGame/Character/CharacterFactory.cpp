#include "CharacterFactory.h"
#include <memory>
#include <random>

//初期値定数
#include "../Constant/InitialValue.h"

//タグ
#include "../Constant/Tag.h"

//キャラクター
#include "CharacterBase.h"
#include "Player/Player.h"
#include "Enemy/Enemy.h"

//状態コンポーネント
#include "../Component/State/StateComponent.h"

//位置情報コンポーネント
#include "../Component/Transform/TransformComponent.h"

//移動コンポーネント
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Movement/Player/PlayerMovementComputer.h"
#include "../Component/Movement/Enemy/EnemyMovementComputer.h"

//描画コンポーネント
#include "../Component/Render/RenderComponent.h"
#include "../Component/Render/ModelRenderer.h"

//アニメーションコンポーネント
#include "../Component/Animation/AnimatorComponent.h"
#include "../Component/Animation/Player/PlayerAnimation.h"
#include "../Component/Animation/Enemy/EnemyAnimation.h"

//入力情報
#include "../Input/InputSystems.h"
#include "Player/PlayerInput/KeyBoardAndMousePlayerInput.h"
#include "Player/PlayerInput/GamePadPlayerInput.h"

//プレイヤー生成
std::unique_ptr<CharacterBase> CharacterFactory::CreatePlayer(Vec3* camera_position_form_target_vector_)
{
	//入力をキーボード&マウスかゲームパッドか確認して生成
	std::unique_ptr<ICharacterInput> input;
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

	//状態コンポーネント生成
	StateComponent state;

	//位置座標コンポーネント生成
	TransformComponent transform(player_initialize_position, character_initialize_forward, character_initialize_yaw_radian);

	//動態計算機作成
	std::unique_ptr<IMovementComputer> movement_compurter = std::make_unique<PlayerMovementComputer>(input.get(), player_move_speed, camera_position_form_target_vector_);

	//移動コンポーネント作成
	MovementComponent movement(ComponentLayer::Player, std::move(movement_compurter));

	//描画機作成
	std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Player);

	//描画コンポーネント生成
	RenderComponent render(std::move(renderer), ComponentLayer::Player);

	//プレイヤーアニメーション作成
	std::unique_ptr<IAnimation> animation = std::make_unique<PlayerAnimation>();

	//アニメーションコンポーネント生成
	AnimatorComponent animator(std::move(animation));

	//プレイヤー生成して返す
	return std::make_unique<Player>(std::move(input), state, transform, movement, animator, render);
}

//敵生成
std::unique_ptr<CharacterBase> CharacterFactory::CreateEnemy(Vec3* player_position_, int index_)
{
	//状態コンポーネント生成
	StateComponent state;

	//敵の生成位置を決定
	Vec3 enemy_spawn_position = Vec3::Zero();
	switch(DxLib::GetRand(3))
	{
	case 0:
		enemy_spawn_position = enemy_initialize_position_01;
		break;

	case 1:
		enemy_spawn_position = enemy_initialize_position_02;
		break;

	case 2:
		enemy_spawn_position = enemy_initialize_position_03;
		break;

	case 3:
		enemy_spawn_position = enemy_initialize_position_04;
		break;

	default:
		break;
	}

	//位置座標コンポーネント生成
	TransformComponent transform(enemy_spawn_position, character_initialize_forward, character_initialize_yaw_radian);

	//動態計算機作成
	std::unique_ptr<IMovementComputer> movement_compurter = std::make_unique<EnemyMovementComputer>(enemy_move_speed, player_position_);

	//移動コンポーネント作成
	MovementComponent movement(ComponentLayer::Enemy, std::move(movement_compurter));

	//描画機作成
	std::unique_ptr<IRenderer> renderer = std::make_unique<ModelRenderer>(ModelTag::Enemy, index_);

	//描画コンポーネント生成
	RenderComponent render(std::move(renderer), ComponentLayer::Enemy);

	//敵アニメーション作成
	std::unique_ptr<IAnimation> animation = std::make_unique<EnemyAnimation>(index_);

	//アニメーションコンポーネント生成
	AnimatorComponent animator(std::move(animation));

	//プレイヤー生成して返す
	return std::make_unique<Enemy>(state, transform, movement, animator, render);
}
