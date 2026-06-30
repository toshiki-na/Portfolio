#include "NarrowColliderFactory.h"
#include <memory>
#include "NarrowCollider.h"
#include "../../../Utility/Vec3.h"
#include "../../../Utility/Quaternion.h"

//ü•ªÕ“Ë”»’è‚Ì¶¬
std::unique_ptr<NarrowCollider> NarrowColliderFactory::CreateRayCollider(Vec3 start_, Vec3 end_)
{
	return std::make_unique<NarrowCollider>(start_, end_);
}

//‹…Œ`Õ“Ë”»’è‚Ì¶¬
std::unique_ptr<NarrowCollider> NarrowColliderFactory::CreateSphereCollider(Vec3 position_, float radius_)
{
	return std::make_unique<NarrowCollider>(position_, radius_);
}

//OBB‚Ì¶¬
std::unique_ptr<NarrowCollider> NarrowColliderFactory::CreateOBB(Vec3 position_, Vec3 half_scale_, Quaternion rotate_)
{
	return std::make_unique<NarrowCollider>(position_, half_scale_, rotate_);
}