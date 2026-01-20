#ifndef MODEL_MANAGER_H
#define MODEL_MANAGER_H

#include <vector>
#include <unordered_map>
#include "../Constant/Tag.h"

class ModelManager
{
public:
	//コンストラクタ
	ModelManager() = default;

	//デストラクタ
	~ModelManager()
	{
		//モデルの全削除
		AllDelete();
	}

	//読み込み
	void Load(ModelTag tag_);

	//削除
	void Delete(ModelTag tag_);

	//全削除
	void AllDelete();

	//ハンドルの取得
	int GetHandle(ModelTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<ModelTag, int> model_handles_list;
};
#endif