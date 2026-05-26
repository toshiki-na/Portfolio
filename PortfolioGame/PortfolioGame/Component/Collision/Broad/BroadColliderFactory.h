#ifndef BROAD_COLLIDER_FACTORY_H
#define BROAD_COLLIDER_FACTORY_H

#include <memory>
#include "BroadCollider.h"

class BroadColliderFactory
{
	//ä»à’è’ìÀîªíËÇÃê∂ê¨
	static std::unique_ptr<BroadCollider> Create(Vec3 positon_ = Vec3::Zero(), Vec3 scale_ = Vec3::Zero());
};
#endif