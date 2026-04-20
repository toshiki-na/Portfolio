#include "CharacterManager.h"

//プレイヤーの生成
void CharacterManager::CreatePlayer(Vec3* camera_position_form_target_vector_)
{
	if (player == nullptr)
	{
		player = CharacterFactory::CreatePlayer(camera_position_form_target_vector_);
	}
}

//敵の生成
void CharacterManager::CreateEnemy()
{
	enemies_list.push_back(CharacterFactory::CreateEnemy());
}

//更新
void CharacterManager::Update()
{
	//プレイヤー更新コンポーネント登録
	if (player->GetActive() == true)
	{
		//移動コンポーネント
		movement_system.Register(player->GetMovement(), ComponentLayer::Player);

		//描画コンポーネント
		rendering_system.Register(player->GetRender(), ComponentLayer::Player);
	}

	//敵更新コンポーネント登録
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