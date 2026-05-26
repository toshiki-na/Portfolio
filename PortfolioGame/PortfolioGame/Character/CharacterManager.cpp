#include "CharacterManager.h"
#include "../Constant/Tag.h"
#include "../Constant/InitialValue.h"
#include "../TimeManager/TimeManager.h"
#include "../Scene/SceneManager.h"

//キャラクター生成
void CharacterManager::CreateCharacter(CharacterType type_, Vec3* vector_)
{
	switch (type_)
	{
		//プレイヤー生成
	case CharacterType::Player:
		CreatePlayer(vector_);
		break;

		//敵生成
	case CharacterType::Enemy:
		CreateEnemy(vector_);
		break;

	default:
		break;
	}
}

//プレイヤーの生成
void CharacterManager::CreatePlayer(Vec3* camera_position_form_target_vector_)
{
	if (player == nullptr)
	{
		player = CharacterFactory::Create(CharacterType::Player, camera_position_form_target_vector_);
	}
}

//敵の生成
void CharacterManager::CreateEnemy(Vec3* player_position_)
{
	enemies_list.push_back(CharacterFactory::Create(CharacterType::Enemy, player_position_));
}

//敵の自動生成
void CharacterManager::AutoEnemySpawn()
{
	//現在のゲーム時間を計測
	now_game_time += TimeManager::Instance().GetDeltaTime();

	if (now_game_time > 20.0f && enemies_list.size() == 0 && spawn_enemy_count < max_enemy_count)
	{
		CreateCharacter(CharacterType::Enemy, player->GetTransform()->GetPositionPtr());
	}

	//float frame_delta_time = TimeManager::Instance().GetDeltaTime();

	////現在のゲーム時間を計測
	//now_game_time += frame_delta_time;
	//enemy_spawn_interval_counter += frame_delta_time;

	////1分に1秒ずつスポーンタイマー短縮
	//enemy_spawn_interval -= now_game_time / 60.0f;

	////マイナスにならないように調整
	//if (enemy_spawn_interval < 0.0f)
	//{
	//	enemy_spawn_interval = 0.0f;
	//}

	////スポーン時間毎に敵生成(生成数上限まで)
	//if (enemy_spawn_interval_counter >= enemy_spawn_interval && spawn_enemy_count < max_enemy_count)
	//{
	//	CreateCharacter(CharacterType::Enemy, player->GetTransform()->GetPositionPtr());

	//	//生成数カウント
	//	spawn_enemy_count++;
	//}
}

//死亡敵の削除
void CharacterManager::DeleteDeadEnemy()
{
	for(auto itr = enemies_list.begin(); itr != enemies_list.end(); itr++)
	{
		if ((*itr)->GetActive() == false)
		{
			enemies_list.erase(itr);
		}
	}

	//敵が全部消滅かつ敵の最大生成数に達していたらゲームシーン終了(クリア)
	if(enemies_list.size() == 0 && spawn_enemy_count == max_enemy_count)
	{ 
		SceneManager::Instance().ChangeSceneStep(SceneStep::Terminate);
	}
}

//更新
void CharacterManager::Update()
{
	//プレイヤー更新コンポーネント登録
	if (player->GetActive() == true)
	{
		//移動コンポーネント
		movement_system.Register(player->GetMovement());

		//アニメーションコンポーネント
		animation_system.Register(player->GetAnimator());

		//描画コンポーネント
		rendering_system.Register(player->GetRender());
	}

	//死亡敵の削除
	DeleteDeadEnemy();

	//敵の自動生成
	AutoEnemySpawn();

	//敵更新コンポーネント登録
	for (auto& Enemy : enemies_list)
	{
		if (Enemy->GetActive() == true)
		{
			//移動コンポーネント
			movement_system.Register(Enemy->GetMovement());

			//アニメーションコンポーネント
			animation_system.Register(Enemy->GetAnimator());

			//描画コンポーネント
			rendering_system.Register(Enemy->GetRender());
		}
	}
}