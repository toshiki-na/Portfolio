#include "PlayerAnimation.h"
#include <DXLib.h>
#include "../../../ResourceManager/ResourceSystemManager.h"
#include "../../../TimeManager/TimeManager.h"
#include "../../../Scene/SceneManager.h"

//初期化
void PlayerAnimation::Initialize()
{
	//モデルハンドルの設定
	model_handle = ResourceSystemManager::Instance().GetModelManager().GetHandle(ModelTag::Player);

	//プレイヤーのアニメーションハンドルの設定
	AnimationResourceManager& animation_resource_manager = ResourceSystemManager::Instance().GetAnimationManager();
	handles.emplace(StateType::Idle, animation_resource_manager.GetHandle(AnimationTag::PlayerIdle));
	handles.emplace(StateType::Move, animation_resource_manager.GetHandle(AnimationTag::PlayerMove));
	handles.emplace(StateType::Attack01, animation_resource_manager.GetHandle(AnimationTag::PlayerAttack01));
	handles.emplace(StateType::Attack02, animation_resource_manager.GetHandle(AnimationTag::PlayerAttack02));
	handles.emplace(StateType::Jump, animation_resource_manager.GetHandle(AnimationTag::PlayerJump));
	handles.emplace(StateType::Avoid, animation_resource_manager.GetHandle(AnimationTag::PlayerAvoid));
	handles.emplace(StateType::Dead, animation_resource_manager.GetHandle(AnimationTag::PlayerDead));

	//待機アニメーションをアタッチ
	anim_index = DxLib::MV1AttachAnim(model_handle, 0, handles[StateType::Idle]);

	//アニメーション時間の初期値設定
	anim_time = 0.0f;

	//総時間の取得
	anim_total_time = DxLib::MV1GetAttachAnimTotalTime(model_handle, anim_index);
}


//アニメーションの変更
void PlayerAnimation::Change(StateType state_)
{
	//アニメーションのデタッチ
	DxLib::MV1DetachAnim(model_handle, anim_index);

	//変更アニメーションのアタッチ
	anim_index = DxLib::MV1AttachAnim(model_handle, 0, handles[state_]);

	//総時間の取得
	anim_total_time = DxLib::MV1GetAttachAnimTotalTime(model_handle, anim_index);

	//アニメーションの現在時間をリセット
	anim_time = 0.0f;

	//アニメーション時間の設定
	DxLib::MV1SetAttachAnimTime(model_handle, anim_index, anim_time);
}

//更新
void PlayerAnimation::Update()
{
	//初回のみ初期化処理
	if(first_time_update == true)
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
			//ジャンプ
		case StateType::Jump:
			//回避
		case StateType::Avoid:
			//死亡
		case StateType::Dead:
			anim_time += 60.0f * TimeManager::Instance().GetDeltaTime();
			break;

			//アニメーション時間を進める(120コマで1秒とする)
			//攻撃1
		case StateType::Attack01:
			//攻撃2
		case StateType::Attack02:
			anim_time += 120.0f * TimeManager::Instance().GetDeltaTime();
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
			//死亡アニメーション終わりならゲームシーン終了
			else if (state->GetState() == StateType::Dead)
			{
				state->ChangeActive();
				SceneManager::Instance().ChangeSceneStep(SceneStep::Terminate);
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
	DxLib::MV1SetAttachAnimTime(model_handle, anim_index, anim_time);
}