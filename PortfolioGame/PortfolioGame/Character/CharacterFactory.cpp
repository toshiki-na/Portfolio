#include "CharacterFactory.h"
#include <memory>
#include "../Constant/Tag.h"
#include "CharacterBase.h"
#include "Player/Player.h"
#include "../Component/Movement/MovementComponent.h"
#include "../Component/Movement/Player/PlayerMoveVectorComputer.h"
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
	//入力受付システム確認
	InputSystems& input_system = InputSystems::Instance();

	//ゲームパッド
	if (input_system.GetGamePadInput().GetConnectedGamePadCount() > 0)
	{
		std::unique_ptr<IPlayerInput> input = std::make_unique<GamePadPlayerInput>();

		std::unique_ptr<IMoveVectorComputer> move_vec_compurter = std::make_unique<PlayerMoveVectorComputer>(std::move(input));

		MovementComponent movement(std::move(move_vec_compurter));

		return std::make_unique<Player>(movement);
	}

	//キーボード&マウス
	return std::make_unique<Player>(std::make_unique<MovementComponent>(std::make_unique<PlayerMoveVectorComputer>(std::make_unique<KeyBoardAndMousePlayerInput>())));
}

//敵生成
std::unique_ptr<CharacterBase> CharacterFactory::CreateEnemy()
{
}
