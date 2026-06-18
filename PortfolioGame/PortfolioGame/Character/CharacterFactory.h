#ifndef CHARACTER_FACTORY_H
#define CHARACTER_FACTORY_H

#include <memory>
#include "../Constant/Tag.h"
#include "CharacterBase.h"

class CharacterFactory
{
public:
	//ÉvÉåÉCÉÑÅ[ê∂ê¨
	static std::unique_ptr<CharacterBase> CreatePlayer(Vec3* camera_position_form_target_vector_);

	//ìGê∂ê¨
	static std::unique_ptr<CharacterBase> CreateEnemy(Vec3* player_position_, int index_);
};
#endif