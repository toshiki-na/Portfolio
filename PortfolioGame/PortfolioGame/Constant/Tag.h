#ifndef TAG_H
#define TAG_H

//シーンの種類一覧
enum class SceneType
{
	Title,		//タイトル
	Game,		//ゲーム
	Clear,		//クリア
	GameOver	//ゲームオーバー
};

//シーンのステップ一覧
enum class SceneStep
{
	Initialize,	//初期化
	Update,		//ループ
	Terminate	//終了
};

//リソース管理用タグ一覧
//3Dモデル
enum class ModelTag
{
	Stage,	//ステージ
	Player,	//プレイヤー
	Enemy,	//敵
};
//アニメーション
enum class AnimationTag
{
};
//2D画像
enum class ImageTag
{
};
//サウンド
enum class AudioTag
{
};
#endif