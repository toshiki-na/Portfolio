#ifndef STAGE_OBJECT_FACTORY_H
#define STAGE_OBJECT_FACTORY_H

#include <memory>
#include "StageObject/StageObjectBase.h"
#include "../Constant/Tag.h"

class StageObjectFactory
{
public:
	//ステージオブジェクト生成
	static std::unique_ptr<StageObjectBase> Create(StageObjectType type_);
};
#endif