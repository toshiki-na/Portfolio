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
		player = CharacterFactory::CreatePlayer( camera_position_form_target_vector_);
	}
}

//敵の生成
void CharacterManager::CreateEnemy(Vec3* player_position_)
{
	//敵のオブジェクトプールを生成
	for (int i = 0; i < max_enemy_count; ++i)
	{
		enemies[i] = CharacterFactory::CreateEnemy(player_position_, i);
	}
}

//敵の自動生成
void CharacterManager::AutoEnemySpawn()
{
	//1フレームの経過時間を取得
	float frame_delta_time = TimeManager::Instance().GetDeltaTime();

	//現在のゲーム時間を計測
	enemy_spawn_interval_decrease_counter += frame_delta_time;
	enemy_spawn_interval_counter += frame_delta_time;

	//1分ずつスポーンタイマー短縮
	if (enemy_spawn_interval_decrease_counter >= ONE_MINUTE_SECONDS)
	{
		enemy_spawn_interval-= enemy_spawn_interval_decrease_par_minute;
		enemy_spawn_interval_decrease_counter -= ONE_MINUTE_SECONDS;
	}

	//マイナスにならないように調整
	if (enemy_spawn_interval < 0.0f)
	{
		enemy_spawn_interval = 0.0f;
	}

	//スポーン時間毎に敵生成(生成数上限まで)
	if (enemy_spawn_interval_counter >= enemy_spawn_interval && arrive_enemy_count < max_enemy_count)
	{

		//生成したので生成間隔計測リセット
		enemy_spawn_interval_counter -= enemy_spawn_interval;
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

	//敵の自動生成
	AutoEnemySpawn();

	//敵更新コンポーネント登録
	for (auto& Enemy : enemies)
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