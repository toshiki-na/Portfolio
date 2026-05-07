#include "BroadColliderFactory.h"
#include <memory>
#include "BroadCollider.h"

//ä»à’è’ìÀîªíËÇÃê∂ê¨
std::unique_ptr<BroadCollider> BroadColliderFactory::Create(Vec3 positon_ = Vec3::Zero(), Vec3 scale_ = Vec3::Zero(), float object_height_ = 0.0f)
{
	return std::make_unique<BroadCollider>(positon_, scale_, object_height_);
}
