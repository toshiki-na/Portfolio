#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

class AudioManager
{
public:
	//コンストラクタ
	AudioManager() = default;

	//デストラクタ
	~AudioManager()
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

	//ハンドルの取得
	int GetHandle(AudioTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<AudioTag, int> audio_handles_list;
};
#endif