#ifndef PLAYER_MOVE_VECTOR_COMPUTER_H
#define PLAYER_MOVE_VECTOR_COMPUTER_H

#include <memory>
#include "../../../Utility/Vec3.h"
#include "../IMoveVectorComputer.h"
#include "../../../Character/Player/PlayerInput/IPlayerInput.h"

class PlayerMoveVectorComputer : public IMoveVectorComputer
{
public:
	//コンストラクタ
	PlayerMoveVectorComputer(std::unique_ptr<IPlayerInput> input_, Vec3* camera_position_form_target_vector_ = nullptr) :
		input(std::move(input_)),
		camera_position_form_target_vector(camera_position_form_target_vector_)
	{
	}

	//カメラの注視点から位置までのベクトルのセット
	void SetCameraPositionFormTargetVector(Vec3* camera_position_form_target_vector_)
	{
		camera_position_form_target_vector = camera_position_form_target_vector_;
	}

	//移動方向の取得
	Vec3 GetVector() override;

private:
	//移動方向の計算
	Vec3 CalculateMoveVec();

private:
	//プレイヤー入力
	std::unique_ptr<IPlayerInput> input;

	//カメラの注視点から位置までのベクトル
	Vec3* camera_position_form_target_vector;
};
#endif