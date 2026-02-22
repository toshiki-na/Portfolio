#ifndef CAMERA_H
#define CAMERA_H

#include "../Utility/Vec3.h"

class Camera
{
public:
	//コンストラクタ
	Camera() = default;

	//デストラクタ
	~Camera() = default;

public:
	//初期化
	void Initialize();

	//更新
	void Update();

private:
	//位置座標
	Vec3 position{ Vec3::Zero() };

	//注視点
	Vec3 target{ Vec3::Zero() };

	//上方向ベクトル(Y軸正)
	Vec3 up{ 0.0f, 1.0f, 0.0f };
};
#endif