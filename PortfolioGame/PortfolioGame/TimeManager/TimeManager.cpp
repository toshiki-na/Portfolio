#include "TimeManager.h"
#include <DXLib.h>

//シーンの開始
void TimeManager::Initialize()
{
	last_frame_time = GetNowCount() * MILLISECONDS_TO_SECONDS;
}

//更新
void TimeManager::Update()
{
	//現在の時間を更新(ミリ秒から秒に変換)
	now_frame_time = GetNowCount() * MILLISECONDS_TO_SECONDS;

	//前フレームからの経過時間を計算
	delta_time = now_frame_time - last_frame_time;

	//次フレーム用に現在時間を前フレームバッファに入れる
	last_frame_time = now_frame_time;
}