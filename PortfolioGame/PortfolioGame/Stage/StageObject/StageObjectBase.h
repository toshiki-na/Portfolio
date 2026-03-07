#ifndef STAGE_OBJECT_BASE_H
#define STAGE_OBJECT_BASE_H

//ステージオブジェクトインターフェース
class StageObjectBase
{
public:
	//コンストラクタ
	StageObjectBase() = default;

	//デストラクタ
	virtual ~StageObjectBase() = default;

	//描画
	virtual void Draw()const = 0;
};
#endif