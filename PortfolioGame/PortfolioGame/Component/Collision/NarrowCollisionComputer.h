#ifndef NARROW_COLLISION_COMPUTER_H
#define NARROW_COLLISION_COMPUTER_H

#include "Narrow/NarrowCollider.h"

class NarrowCollisionComputer
{
public:
	//ü•ª‚Æü•ª‚ÌÕ“Ë”»’è
	bool CheackCollisionRayAndRay(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

	//‹…‚Æ‹…‚ÌÕ“Ë”»’è
	bool CheackCollisionSphereAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

	//OBB‚ÆOBB‚ÌÕ“Ë”»’è
	bool CheackCollisionOBBAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

	//ü•ª‚Æ‹…‚ÌÕ“Ë”»’è
	bool CheackCollisionRayAndSphere(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

	//ü•ª‚ÆOBB‚ÌÕ“Ë”»’è
	bool CheackCollisionRayAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

	//‹…‚ÆOBB‚ÌÕ“Ë”»’è
	bool CheackCollisionSphereAndOBB(NarrowCollider& collider_01_, NarrowCollider& collider_02_);

private:
	//” \‘¢‘Ì
	struct Box
	{
		//8’¸“_
		Vec3 vertices[8];
	};
};
#endif