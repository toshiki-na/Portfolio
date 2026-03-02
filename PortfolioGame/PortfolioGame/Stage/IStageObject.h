#ifndef INTERFACE_STAGE_OBJECT_H
#define INTERFACE_STAGE_OBJECT_H

//ステージオブジェクトインターフェース
class IStageObject
{
public:
	//デストラクタ
	virtual ~IStageObject() = default;

	//描画
	virtual void Draw()const = 0;
};
#endif