#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "ResourceFiles.h"
#include "ModelResourceManager.h"
#include "AnimationResourceManager.h"
#include "ImageResourceManager.h"
#include "AudioResourceManager.h"

class ResourceSystems
{
//シングルトンオブジェクト*******************************
public:
	//唯一のインスタンスの取得
	static ResourceSystems& Instance()
	{
		static ResourceSystems instance;
		return instance;
	}

	//コピー&ムーブ禁止
	ResourceSystems(const ResourceSystems&) = delete;
	ResourceSystems& operator=(const ResourceSystems&) = delete;
	ResourceSystems(ResourceSystems&&) = delete;
	ResourceSystems& operator=(ResourceSystems&&) = delete;

private:
	//コンストラクタ
	ResourceSystems() = default;

	//デストラクタ
	~ResourceSystems() = default;
//*********************************************************

public:
	//リソースファイルデータを取得
	inline ResourceFiles& GetResourceFiles()
	{
		return resource_files;
	}

	//3Dモデル管理オブジェクトの取得
	inline ModelResourceManager& GetModelManager()
	{
		return model_manager;
	}

	//アニメーション管理オブジェクトの取得
	inline AnimationResourceManager& GetAnimationManager()
	{
		return animation_manager;
	}

	//2D画像管理オブジェクトの取得
	inline ImageResourceManager& GetImageManager()
	{
		return image_manager;
	}

	//サウンド管理オブジェクトの取得
	inline AudioResourceManager& GetAudioManager()
	{
		return audio_manager;
	}

private:
	//リソースファイルデータ
	ResourceFiles resource_files;

	//3Dモデル管理オブジェクト
	ModelResourceManager model_manager;

	//アニメーション管理オブジェクト
	AnimationResourceManager animation_manager;

	//2D画像管理オブジェクト
	ImageResourceManager image_manager;

	//サウンド管理オブジェクト
	AudioResourceManager audio_manager;
};
#endif