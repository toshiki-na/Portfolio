#include "BroadColliderFactory.h"
#include <memory>
#include "BroadCollider.h"

//ŠÈˆÕÕ“Ë”»’è‚Ì¶¬
std::unique_ptr<BroadCollider> BroadColliderFactory::Create(Vec3 positon_, Vec3 scale_)
{
	return std::make_unique<BroadCollider>(positon_, scale_);
}
