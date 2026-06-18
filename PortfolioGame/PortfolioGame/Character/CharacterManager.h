#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <memory>
#include <array>
#include "../Constant/InitialValue.h"
#include "../Utility/Vec3.h"
#include "CharacterFactory.h"
#include "CharacterBase.h"

//コンポーネントシステム
#include "../Component/Movement/MovementSystem.h"
#include "../Component/Animation/AnimationSystem.h"
#include "../Component/Render/RenderingSystem.h"

class CharacterManager
{
public:
	//コンストラクタ
	CharacterManager(MovementSystem& movement_system_,AnimationSystem& animation_system_, RenderingSystem& rendering_system_) :
		movement_system(movement_system_),
		animation_system(animation_system_),
		rendering_system(rendering_system_)
	{
	}

	//デストラクタ
	~CharacterManager() = default;

	//コピー&ムーブ禁止
	CharacterManager(const CharacterManager&) = delete;
	CharacterManager& operator=(const CharacterManager&) = delete;
	CharacterManager(CharacterManager&&) = delete;
	CharacterManager& operator=(CharacterManager&&) = delete;

	//キャラクター生成(Vec3*はプレイヤーならカメラの注視点からのベクトル、敵ならプレイヤー座標)
	void CreateCharacter(CharacterType type_, Vec3* vector_);

	//プレイヤーHPの取得
	int GetPlayerHP()
	{
		return player->GetHP();
	}

	//プレイヤー座標の取得
	TransformComponent* GetPlayerTransform()
	{
		return player->GetTransform();
	}

	//更新
	void Update();

private:
	//プレイヤーの生成
	void CreatePlayer(Vec3* camera_position_form_target_vector_);

	//敵の生成
	void CreateEnemy(Vec3* player_position);

	//敵の自動生成
	void AutoEnemySpawn();

private:
	//プレイヤー
	std::unique_ptr<CharacterBase> player;

	//敵
	std::array<std::unique_ptr<CharacterBase>, max_enemy_count> enemies;

	//コンポーネントシステム
	//移動
	MovementSystem& movement_system;

	//アニメーション
	AnimationSystem& animation_system;

	//描画
	RenderingSystem& rendering_system;

	//生存してる敵の数
	int arrive_enemy_count{ 0 };

	//敵の生成間隔
	float enemy_spawn_interval{ 20.0f };

	//生成間隔の計測用
	float enemy_spawn_interval_counter{ 0.0f };

	//1分毎の敵の生成間隔の減少量
	float enemy_spawn_interval_decrease_par_minute{ 1.0f };

	//敵の生成間隔減少の計測用
	float enemy_spawn_interval_decrease_counter{ 0.0f };
};
#endif