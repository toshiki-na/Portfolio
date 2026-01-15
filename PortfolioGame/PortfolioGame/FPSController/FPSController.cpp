#include "FPSController.h"
#include <string>
#include <DXLib.h>

//前フレームの終了時間を設定
void FPSController::SetNowIsPreFrameTime()
{
	pre_frame_time = GetNowCount();
}

//スクリーンフリップ
void FPSController::ScreenFlip()
{
	//fps制御(上限が0未満の場合は上限無しとして即スクリーンフリップ)
	if (fps_limit > 0.0f)
	{

	}

	//fps値を描画
	Draw();

	//DXライブラリのスクリーンフリップを実行
	DxLib::ScreenFlip();

	//fps値計測
	fps_counter++;

	//現在時間を前フレームの終了時間として保持
	SetNowIsPreFrameTime();
}

//fps値を描画
void FPSController::Draw()
{
	//fps値
	DrawString(0, 0, std::to_string(fps_counter).c_str(), GetColor(255, 255, 255));
}
