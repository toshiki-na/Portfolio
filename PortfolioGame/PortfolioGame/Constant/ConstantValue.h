#ifndef CONSTANT_VALUE_H
#define CONSTANT_VALUE_H

#include <numbers>

/* 定数宣言場所 */
//画面の縦横幅
constexpr float SCREEN_WIDTH = 1600.0f;
constexpr float SCREEN_HEIGHT = 900.0f;

//msからsに変換する係数
constexpr float MILLISECONDS_TO_SECONDS = 0.001f;

//1分
constexpr float ONE_MINUTE_SECONDS = 60.0f;

//角度を度数法からラジアン法に変換する係数
constexpr float DIGREE_TO_RADIAN = static_cast<float>(std::numbers::pi) / 180.0f;

//入力の遊び値
constexpr float INPUT_MARGIN = 0.5f;
#endif