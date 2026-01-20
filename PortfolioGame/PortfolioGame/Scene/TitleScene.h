#ifndef TITLESCENE_H
#define TITLESCENE_H

#include "SceneBase.h"
#include <memory>
#include "../Constant/Tag.h"

class TitleScene : public SceneBase
{
public:
	//コンストラクタ
	TitleScene()
	{
		//シーンタイプ設定
		scene_type = SceneType::Title;
	}

	//デストラクタ
	~TitleScene() override = default;

private:
	//初期化
	void Initialize() override;

	//ループ
	void Update() override;

	//終了
	std::unique_ptr<SceneBase> Terminate() override;
};
#endif