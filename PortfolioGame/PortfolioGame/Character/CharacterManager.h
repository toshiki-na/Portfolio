#ifndef CHARACTER_MANAGER_H
#define CHARACTER_MANAGER_H

#include <memory>
#include <vector>
#include "../Constant/Tag.h"
#include "CharacterFactory.h"
#include "CharacterBase.h"

//コンポーネントシステム
#include "../Component/Movement/MovementSystem.h"
#include "../Component/Render/RenderingSystem.h"

class CharacterManager
{
public:
	//コンストラクタ
	CharacterManager(MovementSystem& movement_system_, RenderingSystem& rendering_system_) :
		movement_system(movement_system_),
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

	//キャラクターの生成
	void Create(CharacterType type_);

	//プレイヤー座標の取得
	TransformComponent* GetPlayerTransform()
	{
		return player->GetTransform();
	}

	//更新
	void Update();

private:
	//プレイヤー
	std::unique_ptr<CharacterBase> player;

	//敵
	std::vector<std::unique_ptr<CharacterBase>> enemies_list;

	//コンポーネントシステム
	//移動
	MovementSystem& movement_system;

	//描画
	RenderingSystem& rendering_system;
};
#endif