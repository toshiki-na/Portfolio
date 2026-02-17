#ifndef INPUT_SYSTEM_H
#define INPUT_SYSTEM_H

class InputSystem
{
//シングルトンオブジェクト*******************************
public:
	static InputSystem& Instance()
	{
		static InputSystem instance;
		return instance;
	}

	//コピー&ムーブ禁止
	InputSystem(const InputSystem&) = delete;
	InputSystem& operator=(const InputSystem&) = delete;
	InputSystem(InputSystem&&) = delete;
	InputSystem& operator=(InputSystem&&) = delete;

private:
	//コンストラクタ
	InputSystem() = default;

	//デストラクタ
	~InputSystem() = default;
//*********************************************************

public:
	bool GetKeyBordInput()
};
#endif