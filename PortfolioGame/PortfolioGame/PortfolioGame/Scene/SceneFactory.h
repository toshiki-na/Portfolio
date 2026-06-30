#ifndef SCENE_FACTORY_H
#define SCENE_FACTORY_H

#include <memory>
#include "../Constant/Tag.h"
#include "SceneBase.h"

class SceneFactory
{
public:
	//ÉVÅ[Éìê∂ê¨
	static std::unique_ptr<SceneBase> Create(SceneType scene_type_);
};
#endif