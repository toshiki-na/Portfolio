#include "CharacterManager.h"
#include "../Constant/Tag.h"
#include "../Constant/InitialValue.h"
#include "../TimeManager/TimeManager.h"
#include "../Scene/SceneManager.h"

//更新
void CharacterManager::Update()
{
	//プレイヤーの生存確認
	if (player->GetActive())
	{
		//プレイヤーの更新コンポーネント登録
		RegisterComponent(*player);
	}

	//敵の出現
	EnemySpawn();

	//敵の更新コンポーネント登録
	for (auto& Enemy : enemies)
	{
		//敵の生存確認
		if (Enemy->GetActive() == true)
		{
			RegisterComponent(*Enemy);
		}
	}
}

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

//敵の出現
void CharacterManager::EnemySpawn()
{
	//1フレームの経過時間を取得
	float frame_delta_time = TimeManager::Instance().GetDeltaTime();

	//計測時間加算
	enemy_spawn_interval_counter += frame_delta_time;

}

//キャラクターのコンポーネント登録
void CharacterManager::RegisterComponent(CharacterBase& character_)
{
	//キャラクターの状態取得
	StateType character_state = character_.GetState();

	//キャラクターの状態分けして更新コンポーネント登録
	switch (character_state)
	{
		//待機状態、移動状態、回避状態
	case StateType::Idle:
	case StateType::Move:
	case StateType::Jump:
	case StateType::Avoid:
		//移動コンポーネント
		movement_system.Register(character_.GetMovement());

		//身体の衝突判定

		//アニメーションコンポーネント
		animation_system.Register(character_.GetAnimator());

		//描画コンポーネント
		rendering_system.Register(character_.GetRender());
		break;

		//攻撃状態
	case StateType::Attack01:
	case StateType::Attack02:
		//移動コンポーネント
		movement_system.Register(character_.GetMovement());

		//身体の衝突判定

		//武器の衝突判定

		//アニメーションコンポーネント
		animation_system.Register(character_.GetAnimator());

		//描画コンポーネント
		rendering_system.Register(character_.GetRender());
		break;

		//死亡状態
	case StateType::Dead:
		//アニメーションコンポーネント
		animation_system.Register(character_.GetAnimator());

		//描画コンポーネント
		rendering_system.Register(character_.GetRender());
		break;

		//例外処理
	default:
		break;
	}
}