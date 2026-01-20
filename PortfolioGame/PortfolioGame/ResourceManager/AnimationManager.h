#ifndef ANIMATION_MANAGER_H
#define ANIMATION_MANAGER_H

class AnimationManager
{
public:
	//コンストラクタ
	AnimationManager() = default;

	//デストラクタ
	~AnimationManager()
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

	//ハンドルの取得
	int GetHandle(AnimationTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<AnimationTag, int> animation_handles_list;
};
#endif