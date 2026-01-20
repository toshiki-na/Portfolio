#ifndef IMAGE_MANAGER_H
#define IMAGE_MANAGER_H

class ImageManager
{
public:
	//コンストラクタ
	ImageManager() = default;

	//デストラクタ
	~ImageManager()
	{
		//モデルの全削除
		AllDelete();
	}

	//読み込み
	void Load(ImageTag tag_);

	//削除
	void Delete(ImageTag tag_);

	//全削除
	void AllDelete();

	//ハンドルの取得
	int GetHandle(ImageTag tag_) const;

private:
	//ハンドル一覧
	std::unordered_map<ImageTag, int> image_handles_list;
};
#endif