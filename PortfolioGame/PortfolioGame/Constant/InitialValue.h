#ifndef INITIAL_VALUE_H
#define INITIAL_VALUE_H

#include "ConstantValue.h"
#include "../Utility/Vec3.h"

//カメラ関係
//注視点補正
constexpr Vec3 camera_target_offset = Vec3(0.0f, 100.0f, 0.0f);

//上方向ベクトル
constexpr Vec3 up_vector = Vec3(0.0f, 1.0f, 0.0f);

//視野の最近距離
constexpr float vision_near = 50.0f;

//視野の最遠距離
constexpr float vision_far = 100000.0f;

//ピッチ角の上限
constexpr float pitch_angle_rimit = 89.9f * DIGREE_TO_RADIAN;

//プレイヤー関係初期値
//位置
constexpr Vec3 player_initialize_position = Vec3(0.0f, 0.0f, 0.0f);

//向き
constexpr Vec3 player_initialize_forward = Vec3(0.0f, 0.0f, -1.0f);

//Y軸回転角度
constexpr float player_initialize_yaw_radian = 0.0f;

//移動速度
constexpr float player_move_speed = 100.0f;
#endif