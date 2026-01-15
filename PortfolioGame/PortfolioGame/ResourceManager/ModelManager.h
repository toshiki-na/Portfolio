#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include <unordered_map>
#include "../Constant/Tag.h"

class ModelManager
{
public:
	//コンストラクタ
	ModelManager() = default;

	//デストラクタ
	~ModelManager() = default;

	//読み込み

private:
	//ハンドル一覧
	std::unordered_map<ModelTag, int> model_handles_list;
};
#endif