#include "CollisionManager.h"
#include "Game.h"


CollisionManager::CollisionManager()
{
}


CollisionManager::~CollisionManager()
{
}

bool CollisionManager::gameHeightCollision(const GameObject * const & gameObject)
{

	return gameObject->getPosition().getY() + gameObject->getSizeHeight() >= Game::instance()->getPlayingFieldHeight();
}

bool CollisionManager::gameWidthCollision(const GameObject * const & gameObject)
{
	return gameObject->getPosition().getX() + gameObject->getSizeWidth() >= Game::instance()->getPlayingFieldWidth();
}

bool CollisionManager::gameObjectCollision(const GameObject * const & gameObject1, const GameObject * const & gameObject2)
{
	return false;
}
