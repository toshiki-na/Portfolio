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
	//ƒXƒ‰ƒu–@‚Å‚Ìü•ª‚ÆOBB‚ÌÕ“Ë”»’è
	bool SlabCollision(const NarrowCollider& ray_, const NarrowCollider& box_);

	//•ª—£²’è—‚Å‚ÌOBB‚ÌÕ“Ë”»’è
	bool SATOBBCollision(const NarrowCollider& box_01_, const NarrowCollider& box_02_);

	//•ª—£²’T¸
	bool FindSATAxis(const Vec3& axis_, const NarrowCollider& box_01_, const NarrowCollider& box_02_, const std::array<Vec3, 3>& box_01_axes_, const std::array<Vec3, 3>& box_02_axes_);

};
#endif