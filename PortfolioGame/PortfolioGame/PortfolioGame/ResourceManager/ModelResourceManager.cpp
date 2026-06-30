#include "ModelResourceManager.h"
#include <string>
#include <DXLib.h>
#include "../Constant/Tag.h"
#include "ResourceSystemManager.h"

//読み込み
void ModelResourceManager::Load(ModelTag tag_)
{
	//既に読み込み済みなら何もしない
	if (model_handles.count(tag_) >0)
	{
		return;
	}
	
	//未読み込みなら読み込んで読み込み済み登録
	int ID = DxLib::MV1LoadModel(ResourceSystemManager::Instance().GetResourceFiles().model_files[tag_].c_str());
	model_handles.emplace(tag_, ID);

	//敵モデルなら複製ハンドルも生成
	if (tag_ == ModelTag::Enemy)
	{
		for (auto& EnemyHandle : enemy_handles)
		{
			EnemyHandle = DxLib::MV1DuplicateModel(ID);
		}
	}
}

//削除
void ModelResourceManager::Delete(ModelTag tag_)
{
	//読み込み済みなら削除
	auto itr = model_handles.find(tag_);
	if (itr != model_handles.end())
	{
		DxLib::MV1DeleteModel((*itr).second);
		model_handles.erase(itr);

		//敵モデルなら複製ハンドルも削除
		if (tag_ == ModelTag::Enemy)
		{
			for(auto& EnemyHandle : enemy_handles)
			{
				DxLib::MV1DeleteModel(EnemyHandle);
				EnemyHandle = -1;
			}
		}
	}
}

//全削除
void ModelResourceManager::AllDelete()
{
	for (auto& ModelHandle : model_handles)
	{
		DxLib::MV1DeleteModel(ModelHandle.second);
	}
	model_handles.clear();

	for (auto& EnemyHandle : enemy_handles)
	{
		DxLib::MV1DeleteModel(EnemyHandle);
	}
}

//ハンドルの取得(エラーで-1)
int ModelResourceManager::GetHandle(ModelTag tag_, int index_) const
{
	//敵ハンドルならハンドルプールのインデックスのハンドルを返す
	if (tag_ == ModelTag::Enemy)
	{
		return enemy_handles[index_];
	}

	auto itr = model_handles.find(tag_);
	if (itr != model_handles.end())
	{
		return (*itr).second;
	}
	return -1;
}