#ifndef WALL_H
#define WALL_H

#include "StageObjectBase.h"
#include "../../Utility/Vec3.h"

class Wall : public StageObjectBase
{
public:
	//コンストラクタ
	Wall() = default;

	//描画
	void Draw()const override;

private:
	//位置
	Vec3 position{ Vec3::Zero() };
};
#endif