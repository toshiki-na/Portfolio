#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <memory>
#include "../ResourceManager/ModelManager.h"
#include "../ResourceManager/AnimationManager.h"
#include "../ResourceManager/ImageManager.h"
#include "../ResourceManager/AudioManager.h"

class ResourceSystems
{
public:
	//シングルトンオブジェクト*******************************
public:
	//唯一のインスタンスの取得
	static ResourceSystems* Instance()
	{
		static ResourceSystems instance;
		return &instance;
	}

	//コピー&ムーブ禁止
	ResourceSystems(const ResourceSystems&) = delete;
	ResourceSystems& operator=(const ResourceSystems&) = delete;
	ResourceSystems(ResourceSystems&&) = delete;
	ResourceSystems& operator=(ResourceSystems&&) = delete;

private:
	//コンストラクタ
	ResourceSystems()
	{
	}

	//デストラクタ
	~ResourceSystems()
	{
	}
	//*********************************************************

private:
	std::unique_ptr<>

};
#endif