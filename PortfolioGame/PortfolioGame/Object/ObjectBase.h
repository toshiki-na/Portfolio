#ifndef OBJECT_BASE_H
#define OBJECT_BASE_H

#include "../Utility/Vec3Utility.h"

class ObjectBase
{
public:
	//コンストラクタ
	ObjectBase() = default;
	ObjectBase(Vec3 positon_):
		position(positon_)
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
};
#endif