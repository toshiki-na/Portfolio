#ifndef GROUND_H
#define GROUND_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Ground : public StageObjectBase
{
public:
	//コンストラクタ
	Ground() = default;

	//描画
	void Draw()const override;

private:
	//位置
	Vec3 position{ Vec3::Zero() };
};
#endif