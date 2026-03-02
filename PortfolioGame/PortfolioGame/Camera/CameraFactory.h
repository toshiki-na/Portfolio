#ifndef CAMERA_FACTORY_H
#define CAMERA_FACTORY_H

#include <memory>
#include "Camera.h"

class CameraFactory
{
public:
	//ƒJƒƒ‰¶¬
	static std::unique_ptr<Camera> Create();
};
#endif