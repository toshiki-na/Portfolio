#ifndef NARROW_COLLIDER_FACTORY_H
#define NARROW_COLLIDER_FACTORY_H

#include <memory>
#include "NarrowCollider.h"
#include "../../../Utility/Vec3.h"
#include "../../../Utility/Quaternion.h"

class NarrowColliderFactory
{
	//ü•ªÕ“Ë”»’è‚Ì¶¬
	static std::unique_ptr<NarrowCollider> CreateRayCollider(Vec3 start_, Vec3 end_);

	//‹…Œ`Õ“Ë”»’è‚Ì¶¬
	static std::unique_ptr<NarrowCollider> CreateSphereCollider(Vec3 position_, float radius_);

	//OBB‚Ì¶¬
	static std::unique_ptr<NarrowCollider> CreateOBB(Vec3 position_, Vec3 half_scale_, Quaternion rotate_);
};
#endif