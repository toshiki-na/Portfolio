#ifndef STAGE_CONTEXT_H
#define STAGE_CONTEXT_H

#include <memory>
#include <vector>
#include "../../Constant/Tag.h"
#include "../StageObject/StageObjectBase.h"

class StageContext
{
public:
	//コンストラクタ
	StageContext()
	{
		//ステージ生成
		CreateStage(1);
	}

	//ステージ生成
	void CreateStage(int stage_level_);

private:
	//ステージオブジェクトの生成
	std::unique_ptr<StageObjectBase> Create(StageObjectType object_type_);

public:
	//ステージオブジェクトリスト
	std::vector<std::unique_ptr<StageObjectBase>> stage_objects;
};
#endif