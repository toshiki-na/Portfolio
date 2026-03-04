#ifndef STAGE_CONTEXT_H
#define STAGE_CONTEXT_H

#include <memory>
#include <vector>
#include "../IStageObject.h"
#include "../Ground.h"
#include "../Wall.h"
#include "../Skydome.h"

class StageContext
{
public:
	//コンストラクタ
	StageContext()
	{
		//3つのオブジェクト(床、壁、空)でサイズを事前確保
		stage_objects.reserve(3);

		//オブジェクト生成
		//床
		stage_objects.push_back(std::make_unique<Ground>());

		//壁
		stage_objects.push_back(std::make_unique<Wall>());

		//空
		stage_objects.push_back(std::make_unique<Skydome>());
	}

	//描画
	void Draw() const;

private:
	//ステージオブジェクトリスト
	std::vector<std::unique_ptr<IStageObject>> stage_objects;
};
#endif