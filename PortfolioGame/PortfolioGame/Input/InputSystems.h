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
	InputSystems() = default;

	//デストラクタ
	~InputSystems() = default;
//*********************************************************

public:
	//入力システム
	//マウス
	std::unique_ptr<MouseInput> mouse_input;

	//キーボード
	std::unique_ptr<>

};
#endif