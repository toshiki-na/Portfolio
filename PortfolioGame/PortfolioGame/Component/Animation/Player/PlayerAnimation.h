#ifndef PLAYER_ANIMATION_H
#define PLAYER_ANIMATION_H

#include <unordered_map>
#include <DXLib.h>
#include "../IAnimation.h"
#include "../../../Constant/Tag.h"
#include "../../State/StateComponent.h"

class PlayerAnimation : public IAnimation
{
public:
	//コンストラクタ
	PlayerAnimation() = default;

	//デストラクタ
	~PlayerAnimation()
	{
		//ハンドルの破棄
		handles.clear();
	}

	//状態セット
	void SetStateComponennt(StateComponent* state_) override
	{
		state = state_;
		pre_state = state->GetState();
	}

	//更新
	void Update() override;

private:
	//初期化
	void Initialize();

	//アニメーションの変更
	void Change(StateType stage_) override;

private:
	bool first_time_update{ true };

	//状態コンポーネント
	StateComponent* state{ nullptr };

	//1フレーム前の状態
	StateType pre_state{ StateType::Idle };

	//モデルのハンドル
	int model_handle{ 0 };

	//アニメーションのハンドル
	std::unordered_map<StateType, int> handles;

	//アニメーションをアタッチするインデックス
	int anim_index{ 0 };

	//アニメーションの総時間
	float anim_total_time{ 0.0f };

	//アニメーションの現在時間
	float anim_time{ 0.0f };
};
#endif