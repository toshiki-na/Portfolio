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


private:
	//位置座標
	Vec3 position{ Vec3::Zero() };

	//注視点
	Vec3 target{ Vec3::Zero() };
};
#endif