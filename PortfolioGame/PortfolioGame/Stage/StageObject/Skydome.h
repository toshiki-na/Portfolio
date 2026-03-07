#ifndef SKYDOME_H
#define SKYDOME_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Skydome : public StageObjectBase
{
public:
	//コンストラクタ
	Skydome() = default;

	//描画
	void Draw()const override;

private:
	//位置
	Vec3 position{ Vec3::Zero() };
};
#endif