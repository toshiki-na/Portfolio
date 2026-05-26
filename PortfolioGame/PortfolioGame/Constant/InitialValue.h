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

//キャラクター関係初期値
//キャラクター半径
constexpr float character_radius = 100.0f;

//向き
constexpr Vec3 character_initialize_forward = Vec3(0.0f, 0.0f, 1.0f);

//Y軸回転角度
constexpr float character_initialize_yaw_radian = 180.0f * DIGREE_TO_RADIAN;

//地形との衝突判定用調整ベクトル
constexpr Vec3 coll_adjust_up_vector = Vec3(0.0f, 50.0f, 0.0f);
constexpr Vec3 coll_adjust_down_vector = Vec3(0.0f, -10.0f, 0.0f);

//プレイヤー関係初期値
//位置
constexpr Vec3 player_initialize_position = Vec3(0.0f, 0.0f, 0.0f);

//移動速度
constexpr float player_move_speed = 300.0f;

//敵関係初期値
//位置
constexpr Vec3 enemy_initialize_position_01 = Vec3{ 1200.0f, 0.0f, 0.0f};
constexpr Vec3 enemy_initialize_position_02 = Vec3{ -1200.0f, 0.0f, 0.0f };
constexpr Vec3 enemy_initialize_position_03 = Vec3{ 0.0f, 0.0f, 1200.0f };
constexpr Vec3 enemy_initialize_position_04 = Vec3{ 0.0f, 0.0f, -1200.0f };

//移動速度
constexpr float enemy_move_speed = 300.0f;

//攻撃射程
constexpr float enemy_attack_range = 200.0f;

//最大生成数
constexpr int max_enemy_count = 300;
#endif