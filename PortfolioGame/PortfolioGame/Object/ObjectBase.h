#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../Utility/Vec3.h"

class ObjectBase
{
public:
	//コンストラクタ
	ObjectBase() = default;
	ObjectBase(Vec3 positon_, Vec3 forward_):
		position(positon_),
		forward(forward_)
	{
	}

	//デストラクタ
	virtual ~ObjectBase() = 0;

	//更新
	virtual void Update() = 0;

	//描画
	virtual void Draw() = 0;

protected:
	//位置座標
	Vec3 position;

	//前方向
	Vec3 forward;
};
#endif