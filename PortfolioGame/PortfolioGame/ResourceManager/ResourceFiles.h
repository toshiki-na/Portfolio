#ifndef RESOURCE_FILES_H
#define RESOURCE_FILES_H

#include <string>
#include <unordered_map>
#include "../Constant/Tag.h"

struct ResourceFiles
{
public:
	//3Dモデルのファイルパス保存場所
	std::unordered_map<ModelTag, std::string> model_files_list
	{
		{ModelTag::Ground, {"Resource/Models/Stage/Ground.mv1"}},	//地面
		{ModelTag::Wall, {"Resource/Models/Stage/Wall.mv1"}},		//壁
		{ModelTag::Player, {"Resource/Models/Player/Player.mv1"}},	//プレイヤー
		{ModelTag::Enemy, {"Resource/Models/Enemy/Enemy.mv1"}},		//敵
	};

	//アニメーションのファイルパス保存場所
	std::unordered_map<AnimationTag, std::string> animation_files_list
	{
	};

	//2D画像のファイルパス保存場所
	std::unordered_map<ImageTag, std::string> image_files_list
	{
	};

	//サウンドのファイルパス保存場所
	std::unordered_map<AudioTag, std::string> audio_files_list
	{
	};
};
#endif
