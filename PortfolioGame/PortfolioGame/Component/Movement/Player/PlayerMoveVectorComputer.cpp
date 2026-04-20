#include "PlayerMoveVectorComputer.h"
#include "../../../Constant/InitialValue.h"
#include "../../../Utility/Vec3.h"

//移動方向の取得
Vec3 PlayerMoveVectorComputer::GetVector()
{
	return CalculateMoveVec();
}

//移動方向の計算
Vec3 PlayerMoveVectorComputer::CalculateMoveVec()
{
	//計算結果
	Vec3 result;

	//上下左右の入力
	Vec3 input_vec = input->GetMoveInput();

	//カメラ前方ベクトルがヌルなら入力をそのまま移動に
	if (camera_position_form_target_vector == nullptr)
	{
		result.x = input_vec.x;
		result.y = 0.0;
		result.z = input_vec.y;
	}
	//カメラローカル座標系と入力ベクトルからワールド座標系での移動方向を計算
	else
	{
		//カメラ前方ベクトルはカメラの注視点から位置ベクトルの逆ベクトル
		Vec3 camera_forward = (*camera_position_form_target_vector).Negative();

		//カメラローカル座標系の前方と入力の前後からワールド座標系での前方入力を計算
		Vec3 forward = camera_forward * input_vec.y;

		//カメラローカル座標系の前方と入力の左右からワールド座標系での右方入力を計算(左手系空間なので右方向は上方向ベクトル×前方向ベクトル)
		Vec3 right = Vec3Math::Cross(up_vector, camera_forward) * input_vec.x;

		//前方ベクトルと右方ベクトルの線形結合で移動方向ベクトル計算
		result = forward + right;

		//y軸方向は移動しないので補正
		result.y = 0.0f;
	}

	//正規化
	if (result.LengthSq() > 0.0f)
	{
		result.Normalized();
	}

	//移動方向ベクトルを返す
	return result;
}