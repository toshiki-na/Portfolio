#ifndef TAG_H
#define TAG_H

//シーンの種類
enum class SceneType
{
	None = -1,	//なし
	Title,		//タイトル
	Game,		//ゲーム
	Clear,		//クリア
	GameOver	//ゲームオーバー
};

//シーンのステップ
enum class SceneStep
{
	Initialize,	//初期化
	Update,		//ループ
	Terminate	//終了
};
#endif