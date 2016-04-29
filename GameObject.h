#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "Vector2.h"
#include <string>
class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0;
	virtual std::string getID() const = 0;
	virtual std::string getTextureID() const = 0;
	virtual void draw() = 0;
	virtual void update() = 0;

	Vector2 getPosition() const { return m_position; }
	int getSizeWidth() const { return m_sizeWidth; }
	int getSizeHeight() const { return m_sizeHeight; }
	float getMovementSpeed() const { return m_movementSpeed; }

protected:
	Vector2 m_position;
	Vector2 m_velocity;
	float m_movementSpeed;
	unsigned int m_sizeWidth;
	unsigned int m_sizeHeight;
};
#endif // !GAME_OBJECT_H
