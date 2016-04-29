#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include "GameObject.h"
#include <vector>
#include <memory>
class CollisionManager
{
public:
	CollisionManager();
	~CollisionManager();

	bool gameHeightCollision(const GameObject * const &gameObject); //Test whether gameObject exceeds game's height bounds
	bool gameWidthCollision(const GameObject  * const &gameObject); //Test whether gameObject exceeds game's width bounds
	//Test whether gameObject collides with another gameObject
	bool gameObjectCollision(const GameObject * const &gameObject1, const GameObject * const &gameObject2); 
private:
}; 
#endif // !COLLISION_MANAGER_H

