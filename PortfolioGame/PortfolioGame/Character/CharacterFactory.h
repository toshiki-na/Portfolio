#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include <memory>
#include "../Constant/Tag.h"
#include "CharacterBase.h"

class CharacterFactory
{
public:
	//キャラクター生成
	static std::unique_ptr<CharacterBase> Create(CharacterType type_);

private:
	//プレイヤー生成
	static std::unique_ptr<CharacterBase> CreatePlayer();

	//敵生成
	static std::unique_ptr<CharacterBase> CreateEnemy();
};
#endif