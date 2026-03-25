#include "CharacterManager.h"

//キャラクターの生成
void CharacterManager::Create(CharacterType type_)
{
	switch (type_)
	{
		//プレイヤー
	case CharacterType::Player:
		if (player == nullptr)
		{
			player = CharacterFactory::Create(type_);
		}
		break;

		//敵
	case CharacterType::Enemy:
		enemies_list.push_back(CharacterFactory::Create(type_));
		break;

		//その他
	default:
		break;
	}
}

//更新
void CharacterManager::Update()
{
	//プレイヤー更新登録
	if (player->GetActive() == true)
	{
		//移動コンポーネント
		movement_system.Register(player->GetMovement(), ComponentLayer::Player);

		//描画コンポーネント
		rendering_system.Register(player->GetRender(), ComponentLayer::Player);
	}

	//敵更新登録
	for (auto& Enemy : enemies_list)
	{
		if (Enemy->GetActive() == true)
		{
			//移動コンポーネント
			movement_system.Register(Enemy->GetMovement(), ComponentLayer::Enemy);

			//描画コンポーネント
			rendering_system.Register(Enemy->GetRender(), ComponentLayer::Enemy);
		}
	}
}