#include "EnemyAnimation.h"
#include <DXLib.h>
#include "../../../ResourceManager/ResourceSystemManager.h"
#include "../../../TimeManager/TimeManager.h"

//初期化
void EnemyAnimation::Initialize()
{
	//プレイヤーのアニメーションハンドルの設定
	animation_tags.emplace(StateType::Idle, AnimationTag::EnemyIdle);
	animation_tags.emplace(StateType::Move, AnimationTag::EnemyMove);
	animation_tags.emplace(StateType::Attack01, AnimationTag::EnemyAttack);
	animation_tags.emplace(StateType::Dead, AnimationTag::EnemyDead);

	//モデルハンドルの取得
	int model_handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Enemy, index);

	//待機アニメーションをアタッチ
	anim_index = DxLib::MV1AttachAnim(model_handle, 0, ResourceSystemManager::Instance().GetAnimationManager().GetHandle(AnimationTag::EnemyIdle));

	//アニメーション時間の初期値設定
	anim_time = 0.0f;

	//総時間の取得
	anim_total_time = DxLib::MV1GetAttachAnimTotalTime(model_handle, anim_index);
}


//アニメーションの変更
void EnemyAnimation::Change(StateType state_)
{
	//モデルハンドルの取得
	int model_handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Enemy, index);

	//アニメーションのデタッチ
	DxLib::MV1DetachAnim(model_handle, anim_index);

	//変更アニメーションのアタッチ
	anim_index = DxLib::MV1AttachAnim(model_handle, 0, ResourceSystemManager::Instance().GetAnimationManager().GetHandle(animation_tags[state_]));

	//総時間の取得
	anim_total_time = DxLib::MV1GetAttachAnimTotalTime(model_handle, anim_index);

	//アニメーションの現在時間をリセット
	anim_time = 0.0f;

	//アニメーション時間の設定
	DxLib::MV1SetAttachAnimTime(model_handle, anim_index, anim_time);
}

//更新
void EnemyAnimation::Update()
{
	//初回のみ初期化処理
	if (first_time_update == true)
	{
		Initialize();
		first_time_update = false;
	}

	//現在の状態取得
	StateType now_state = state->GetState();

	//状態が変わっていなければアニメーションを進める
	if (pre_state == now_state)
	{
		//アニメーション毎の1秒とするコマ次第で調整
		switch (now_state)
		{
			//アニメーション時間を進める(60コマで1秒とする)
			//待機
		case StateType::Idle:
			//移動
		case StateType::Move:
			//攻撃
		case StateType::Attack01:
			//死亡
		case StateType::Dead:
			anim_time += 60.0f * TimeManager::Instance().GetDeltaTime();
			break;

			//エラー
		default:
			break;
		}

		//アニメーションの1回が終わった場合
		if (anim_time >= anim_total_time)
		{
			//待機か移動中ならループ
			if (state->GetState() == StateType::Idle || state->GetState() == StateType::Move)
			{
				anim_time -= anim_total_time;
			}
			//死亡アニメーション終わりなら生存フラグをfalseに
			else if (state->GetState() == StateType::Dead)
			{
				state->SetActive(false);
			}
			//それ以外なら待機に
			else
			{
				state->ChangeState(StateType::Idle);
			}
		}
	}
	//状態が変わっていたらアニメーション変更
	else
	{
		Change(now_state);
	}

	//前フレームの状態保存
	pre_state = now_state;

	//アニメーション適用
	DxLib::MV1SetAttachAnimTime(ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Enemy, index), anim_index, anim_time);
}