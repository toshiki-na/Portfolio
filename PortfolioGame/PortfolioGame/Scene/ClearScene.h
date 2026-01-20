#ifndef CLEARSCENE_H
#define CLEARSCENE_H

#include "SceneBase.h"
#include <memory>
#include "../Constant/Tag.h"

class ClearScene : public SceneBase
{
public:
	//コンストラクタ
	ClearScene()
	{
		//シーンタイプ設定
		scene_type = SceneType::Clear;
	}

	//デストラクタ
	~ClearScene()override = default;

private:
	//初期化
	void Initialize() override;

	//ループ
	void Update() override;

	//終了
	std::unique_ptr<SceneBase> Terminate() override;
};
#endif