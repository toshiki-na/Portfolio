#ifndef GROUND_H
#define GROUND_H

#include "IStageObject.h"
#include "../Utility/Vec3.h"

class Ground : public IStageObject
{
public:
	//コンストラクタ
	Ground() = default;

	//デストラクタ
	~Ground() = default;

	//描画
	void Draw()const override;

private:
	//位置
	Vec3 position{ Vec3::Zero() };
};
#endif