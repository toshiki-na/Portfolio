#ifndef INPUT_SYSTEMS_H
#define INPUT_SYSTEMS_H

#include <memory>
#include "MouseInput.h"
#include "KeyBordInput.h"
#include "GamePadInput.h"

class InputSystems
{
//シングルトンオブジェクト*******************************
public:
	static InputSystems& Instance()
	{
		static InputSystems instance;
		return instance;
	}

	//コピー&ムーブ禁止
	InputSystems(const InputSystems&) = delete;
	InputSystems& operator=(const InputSystems&) = delete;
	InputSystems(InputSystems&&) = delete;
	InputSystems& operator=(InputSystems&&) = delete;

private:
	//コンストラクタ
	InputSystems()
	{
		//各入力システムの生成
		mouse = std::make_unique<MouseInput>();
		keybord = std::make_unique<KeyBordInput>();
		gamepad = std::make_unique<GamePadInput>();
	}

	//デストラクタ
	~InputSystems() = default;
//*********************************************************

public:
	//毎フレームの開始時に実行
	void BeginFrame();

	//毎フレームの終了時に実行
	void EndFrame();

private:
	//入力システム
	//マウス
	std::unique_ptr<MouseInput> mouse;

	//キーボード
	std::unique_ptr<KeyBordInput> keybord;

	//ゲームパッド
	std::unique_ptr<GamePadInput> gamepad;
};
#endif