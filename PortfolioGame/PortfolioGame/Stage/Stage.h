#ifndef STAGE_H
#define STAGE_H

#include "StageContext/StageContext.h"

class Stage
{
public:
	//コンストラクタ
	Stage() = default;

	//デストラクタ
	~Stage() = default;

	//描画
	void Draw();

private:
	//ステージオブジェクト集
	StageContext context;
};
#endif