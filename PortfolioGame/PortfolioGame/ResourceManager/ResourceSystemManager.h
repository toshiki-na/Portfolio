#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include "../Constant/Tag.h"
#include "ResourceFiles.h"
#include "ModelResourceManager.h"
#include "AnimationResourceManager.h"
#include "ImageResourceManager.h"
#include "AudioResourceManager.h"

class ResourceSystemManager
{
//シングルトンオブジェクト*******************************
public:
	//唯一のインスタンスの取得
	static ResourceSystemManager& Instance()
	{
		static ResourceSystemManager instance;
		return instance;
	}

	//コピー&ムーブ禁止
	ResourceSystemManager(const ResourceSystemManager&) = delete;
	ResourceSystemManager& operator=(const ResourceSystemManager&) = delete;
	ResourceSystemManager(ResourceSystemManager&&) = delete;
	ResourceSystemManager& operator=(ResourceSystemManager&&) = delete;

private:
	//コンストラクタ
	ResourceSystemManager() = default;

	//デストラクタ
	~ResourceSystemManager() = default;
//*********************************************************

public:
	//シーンの準備(各シーンのリソースのロード)
	void PrepareScene(SceneType scene_type_);

	//シーンの後片付け(各シーンでロードしたリソースの解放)
	void ReleaseScene(SceneType scene_type_);

	//リソースファイルデータの取得
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