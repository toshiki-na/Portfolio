#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

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
	ResourceSystems() = default;

	//デストラクタ
	~ResourceSystems() = default;
	//*********************************************************

public:
	//3Dモデル管理オブジェクトの取得
	inline ModelManager& GetModelManager()
	{
		return model_manager;
	}

	//アニメーション管理オブジェクトの取得
	inline AnimationManager& GetAnimationManager()
	{
		return animation_manager;
	}

	//2D画像管理オブジェクトの取得
	inline ImageManager& GetImageManager()
	{
		return image_manager;
	}

	//サウンド管理オブジェクトの取得
	inline AudioManager& GetAudioManager()
	{
		return audio_manager;
	}

private:
	//3Dモデル管理オブジェクト
	ModelManager model_manager;

	//アニメーション管理オブジェクト
	AnimationManager animation_manager;

	//2D画像管理オブジェクト
	ImageManager image_manager;

	//サウンド管理オブジェクト
	AudioManager audio_manager;
};
#endif