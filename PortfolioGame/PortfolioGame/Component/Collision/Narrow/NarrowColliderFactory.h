#ifndef NARROW_COLLIDER_FACTORY_H
#define NARROW_COLLIDER_FACTORY_H

#include <memory>
#include "NarrowCollider.h"

class NarrowColliderFactory
{
	//è’ìÀîªíËÇÃê∂ê¨
	static std::unique_ptr<NarrowCollider> Create();
};
#endif