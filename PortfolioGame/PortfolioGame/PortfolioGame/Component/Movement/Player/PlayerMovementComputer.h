#ifndef PLAYER_MOVEMENT_COMPUTER_H
#define PLAYER_MOVEMENT_COMPUTER_H

#include <memory>
#include "../../../Utility/Vec3.h"
#include "../IMovementComputer.h"
#include "../../../Character/ICharacterInput.h"
#include "../../../Component/State/StateComponent.h"
#include "../../../Component/Transform/TransformComponent.h"

class PlayerMovementComputer : public IMovementComputer
{
public:
	//コンストラクタ
	PlayerMovementComputer(ICharacterInput* input_, float speed_, Vec3* camera_position_form_target_vector_ = nullptr) :
		input(input_),
		speed(speed_),
		camera_position_form_target_vector(camera_position_form_target_vector_)
	{
	}

	//状態コンポーネント参照先の設定
	void SetStateComponent(StateComponent* state_) override
	{
		state = state_;
	}

	//位置コンポーネント参照先の設定
	void SetTransformComponent(TransformComponent* transform_) override
	{
		transform = transform_;
	}


	//入力アクションの実行
	void InputAction() override;

	//移動の実行
	void Move() override;

private:
	//移動方向の計算
	Vec3 CalculateMoveVec();

private:
	//プレイヤー入力
	ICharacterInput* input;

	//状態
	StateComponent* state{ nullptr };

	//位置情報
	TransformComponent* transform{ nullptr };

	//移動速度(/s)
	float speed{ 0.0f };

	//カメラの注視点から位置までのベクトル
	Vec3* camera_position_form_target_vector;
};
#endif