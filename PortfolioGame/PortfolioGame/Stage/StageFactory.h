#ifndef STAGE_FACTORY_H
#define STAGE_FACTORY_H

#include <memory>
#include "Stage.h"

class StageFactory
{
public:
	//ステージ生成
	static std::unique_ptr<Stage> Create();

};
#endif