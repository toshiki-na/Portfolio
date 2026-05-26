#ifndef STATE_COMPONENT_H
#define STATE_COMPONENT_H

#include "../../Constant/Tag.h"
#include "../../Character/ICharacterInput.h"

class StateComponent
{
public:
	//コンストラクタ
	StateComponent()
	{
		state = StateType::Idle;
	}

	//状態取得
	StateType GetState()const
	{
		return state;
	}

	//状態変更
	void ChangeState(StateType next_state_)
	{
		state = next_state_;
	}

	//生存フラグ取得
	bool IsActive() const
	{
		return active;
	}

	//生存フラグ変更
	void ChangeActive()
	{
		active = false;
	}

	//生存フラグ取得
	int GetHP() const
	{
		return hp;
	}

	//生存フラグ変更
	void AddHP(int add_hp_)
	{
		hp += add_hp_;
	}

private:
	//状態
	StateType state;

	//生存フラグ
	bool active{ true };

	//HP
	int hp{ 100 };
};
#endif