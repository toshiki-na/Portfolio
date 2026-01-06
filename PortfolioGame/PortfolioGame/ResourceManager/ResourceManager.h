#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

class ResourceManager
{
public:
	//シングルトンオブジェクト*******************************
public:
	//唯一のインスタンスの取得
	static ResourceManager* Instance()
	{
		static ResourceManager instance;
		return &instance;
	}

	//コピー&ムーブ禁止
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;
	ResourceManager(ResourceManager&&) = delete;
	ResourceManager& operator=(ResourceManager&&) = delete;

private:
	//コンストラクタ
	ResourceManager()
	{
	}

	//デストラクタ
	~ResourceManager()
	{
	}
	//*********************************************************

public:

private:
	//全データの破棄
	void AllResoureceDelete();
};
#endif