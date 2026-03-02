#ifndef SKYDOME_H
#define SKYDOME_H

#include "IStageObject.h"
#include "../Utility/Vec3.h"

class Skydome : public IStageObject
{
public:
	//コンストラクタ
	Skydome() = default;

	//デストラクタ
	~Skydome() = default;

	//描画
	void Draw()const override;

private:
	//位置
	Vec3 position{ Vec3::Zero() };
};
#endif