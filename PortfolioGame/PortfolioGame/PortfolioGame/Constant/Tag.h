#ifndef TAG_H
#define TAG_H

/* タグ一覧の記述場所 */

//シーンの種類一覧
enum class SceneType
{
	Title,		//タイトル
	Game,		//ゲーム
	Clear,		//クリア
	GameOver,	//ゲームオーバー
};

//シーンのステップ一覧
enum class SceneStep
{
	Initialize,	//初期化
	Update,		//ループ
	Terminate,	//終了
};

//ステージオブジェクト一覧
enum class StageObjectType
{
	SkyDome,	//空
	Ground,		//地面
	Wall,		//壁
};

//キャラクター一覧
enum class CharacterType
{
	None = -1,	//不明
	Player,		//プレイヤー
	Enemy,		//敵
};

//状態一覧
enum class StateType
{
	Idle,		//待機
	Move,		//移動
	Attack01,	//攻撃1
	Attack02,	//攻撃2
	Jump,		//ジャンプ
	Avoid,		//回避
	Dead,		//死亡
};

//コンポーネントレイヤー
enum class ComponentLayer
{
	Player,			//プレイヤー 
	PlayerWeapon,	//プレイヤー武器
	Enemy,			//敵
	EnemyWeapon,	//敵武器
	Stage,			//ステージ
	UI,				//UI
};

//衝突判定形状タグ一覧
enum class ColliderShapeTag
{
	Ray,	//直線
	Sphere,	//球
	Box,	//直方体
};

//衝突判定情報タグ一覧
enum class ColliderInformationTag
{
	Position,	//位置
	Start,		//始点
	End,		//終点
	Radius,		//半径
	Scale,		//サイズ
	Rotate,		//回転角度
};

//リソース管理用タグ一覧
//3Dモデル
enum class ModelTag
{
	Skydome,//空
	Ground,	//地面
	Wall,	//壁
	Player,	//プレイヤー
	Enemy,	//敵
};

//アニメーション
enum class AnimationTag
{
	PlayerIdle,		//プレイヤーの待機
	PlayerMove,		//プレイヤーの移動
	PlayerAttack01,	//プレイヤーの攻撃01
	PlayerAttack02,	//プレイヤーの攻撃02
	PlayerJump,		//プレイヤーのジャンプ
	PlayerAvoid,	//プレイヤーの回避
	PlayerDead,		//プレイヤーの死亡

	EnemyIdle,		//敵の待機
	EnemyMove,		//敵の移動
	EnemyAttack,	//敵の攻撃
	EnemyDead,		//敵の死亡
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