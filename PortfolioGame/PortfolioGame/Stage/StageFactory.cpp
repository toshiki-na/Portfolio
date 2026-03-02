#include "StageFactory.h"
#include <memory>

//ステージ生成
std::unique_ptr<Stage> StageFactory::Create()
{
	return std::make_unique<Stage>();
}