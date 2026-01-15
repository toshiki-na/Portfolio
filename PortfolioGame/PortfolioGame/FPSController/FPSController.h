#ifndef FPSCONTROLLER_H
#define FPSCONTROLLER_H

class FPSController
{
public:
	//コンストラクタ
	FPSController()
	{
	}

	//デストラクタ
	~FPSController() = default;

	//前フレームの終了時間を設定
	void SetNowIsPreFrameTime();

	//スクリーンフリップ
	void ScreenFlip();

private:
	//fps値を描画
	void Draw();

private:
	//現在のfps値
	int now_fps{ 0 };

	//fpsカウンター
	int fps_counter{ 0 };

	//フレームレート上限(0以下の場合は上限無し)
	float fps_limit{ -1.0f };

	//前フレーム終了時の時間
	int pre_frame_time{ 0 };
};
#endif