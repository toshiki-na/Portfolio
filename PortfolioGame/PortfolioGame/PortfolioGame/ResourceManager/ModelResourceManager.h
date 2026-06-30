#ifndef MODEL_RESOURCE_MANAGER_H
#define MODEL_RESOURCE_MANAGER_H

#include <unordered_map>
#include <array>
#include "../Constant/InitialValue.h"
#include "../Constant/Tag.h"

class ModelResourceManager
{
public:
	//コンストラクタ
	ModelResourceManager() = default;

	//デストラクタ
	~ModelResourceManager()
	{
		//モデルの全削除
		AllDelete();
	}

	//コピー&ムーブ禁止
	ModelResourceManager(const ModelResourceManager&) = delete;
	ModelResourceManager& operator=(const ModelResourceManager&) = delete;
	ModelResourceManager(ModelResourceManager&&) = delete;
	ModelResourceManager& operator=(ModelResourceManager&&) = delete;

	//読み込み
	void Load(ModelTag tag_);

	//削除
	void Delete(ModelTag tag_);

	//全削除
	void AllDelete();

	//ハンドルの取得(エラーで-1)
	int GetHandle(ModelTag tag_, int index_ = 0) const;

private:
	//ハンドル一覧
	std::unordered_map<ModelTag, int> model_handles;

	//敵用複製ハンドル
	std::array<int, max_enemy_count> enemy_handles{ -1 };
};
#endif