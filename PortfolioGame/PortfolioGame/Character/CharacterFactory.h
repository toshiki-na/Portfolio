#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include <memory>
#include "../Constant/Tag.h"
#include "CharacterBase.h"

class CharacterFactory
{
public:
	//キャラクター生成(Vec3*はプレイヤーならカメラの注視点からのベクトル、敵ならプレイヤー座標)
	static std::unique_ptr<CharacterBase> Create(CharacterType type_, Vec3* vector_);

private:
	//プレイヤー生成
	static std::unique_ptr<CharacterBase> CreatePlayer(Vec3* camera_position_form_target_vector_);

	//敵生成
	static std::unique_ptr<CharacterBase> CreateEnemy(Vec3* player_position_);
};
#endif