#ifndef ANIMATION_RESOURCE_MANAGER_H
#define ANIMATION_RESOURCE_MANAGER_H

#include <unordered_map>
#include "../Constant/Tag.h"

class AnimationResourceManager
{
public:
	//コンストラクタ
	AnimationResourceManager() = default;

	//デストラクタ
	~AnimationResourceManager()
	{
		//モデルの全削除
		AllDelete();
	}

	//読み込み
	void Load(AnimationTag tag_);

	//削除
	void Delete(AnimationTag tag_);

	//全削除
	void AllDelete();

	//ハンドルの取得(エラーで-1)
	int GetHandle(AnimationTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<AnimationTag, int> animation_handles_list;
};
#endif