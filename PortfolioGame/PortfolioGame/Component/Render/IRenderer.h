#ifndef INTERFACE_RENDERER_H
#define INTERFACE_RENDERER_H

class IRenderer
{
public:
	//デストラクタ
	virtual ~IRenderer() = default;

	//描画
	virtual void Draw() const = 0;
};
#endif