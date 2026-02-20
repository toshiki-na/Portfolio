#ifndef AUDIO_RESOURCE_MANAGER_H
#define AUDIO_RESOURCE_MANAGER_H

#include <unordered_map>
#include "../Constant/Tag.h"

class AudioResourceManager
{
public:
	//コンストラクタ
	AudioResourceManager() = default;

	//デストラクタ
	~AudioResourceManager()
	{
		//モデルの全削除
		AllDelete();
	}

	//読み込み
	void Load(AudioTag tag_);

	//削除
	void Delete(AudioTag tag_);

	//全削除
	void AllDelete();

	//ハンドルの取得(エラーで-1)
	int GetHandle(AudioTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<AudioTag, int> audio_handles_list;
};
#endif