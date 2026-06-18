#ifndef RESOURCE_FILES_H
#define RESOURCE_FILES_H

#include <string>
#include <unordered_map>
#include "../Constant/Tag.h"

struct ResourceFiles
{
public:
	//3Dモデルのファイルパス保存場所
	std::unordered_map<ModelTag, std::string> model_files
	{
		{ModelTag::Ground, {"Resource/Models/Stage/Ground/Ground.mv1"}},	//地面
		{ModelTag::Wall, {"Resource/Models/Stage/Wall/Wall.mv1"}},			//壁
		{ModelTag::Skydome, {"Resource/Models/Stage/Skydome/Skydome.mv1"}},	//空
		{ModelTag::Player, {"Resource/Models/Player/Player.mv1"}},			//プレイヤー
		{ModelTag::Enemy, {"Resource/Models/Enemy/Enemy.mv1"}},				//敵
	};

	//アニメーションのファイルパス保存場所
	std::unordered_map<AnimationTag, std::string> animation_files
	{
		{AnimationTag::PlayerIdle, {"Resource/Animations/Player/Idle.mv1"}},		//プレイヤー待機
		{AnimationTag::PlayerMove, {"Resource/Animations/Player/Run.mv1"}},			//プレイヤーの移動
		{AnimationTag::PlayerAttack01, {"Resource/Animations/Player/Attack01.mv1"}},//プレイヤーの攻撃01
		{AnimationTag::PlayerAttack02, {"Resource/Animations/Player/Attack02.mv1"}},//プレイヤーの攻撃02
		{AnimationTag::PlayerJump, {"Resource/Animations/Player/Jump.mv1"}},		//プレイヤーのジャンプ
		{AnimationTag::PlayerAvoid, {"Resource/Animations/Player/Avoid.mv1"}},		//プレイヤーの回避
		{AnimationTag::PlayerDead, {"Resource/Animations/Player/Dead.mv1"}},		//プレイヤーの死亡

		{AnimationTag::EnemyIdle, {"Resource/Animations/Enemy/Idle.mv1"}},			//敵待機
		{AnimationTag::EnemyMove, {"Resource/Animations/Enemy/Move.mv1"}},			//敵の移動
		{AnimationTag::EnemyAttack, {"Resource/Animations/Enemy/Attack.mv1"}},		//敵の攻撃
		{AnimationTag::EnemyDead, {"Resource/Animations/Enemy/Dead.mv1"}},			//敵の死亡
	};

	//2D画像のファイルパス保存場所
	std::unordered_map<ImageTag, std::string> image_files
	{
	};

	//サウンドのファイルパス保存場所
	std::unordered_map<AudioTag, std::string> audio_files
	{
	};
};
#endif
