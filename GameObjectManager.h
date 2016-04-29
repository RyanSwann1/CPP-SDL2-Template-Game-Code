#ifndef GAME_OBJECT_MANAGER_H
#define GAME_OBJECT_MANAGER_H

#include "GameObject.h"
#include <vector>
#include <memory>
class GameObjectManager
{
public:
	GameObjectManager();
	~GameObjectManager();


	void draw();
	void update();
	void initGameObject(std::unique_ptr<GameObject>& gameObject) { m_gameObjects.emplace_back(std::unique_ptr<GameObject>(std::move(gameObject))); }
	void addGameObject(std::unique_ptr<GameObject>& gameObject) { m_newGameObjects.emplace_back(std::unique_ptr<GameObject>(std::move(gameObject))); }
	std::vector<std::unique_ptr<GameObject>>& getGameObjects() { return m_gameObjects; }
	std::vector<std::unique_ptr<GameObject>>& clearGameObjects() { m_gameObjects.clear(); }
	
private:	
	std::vector<std::unique_ptr<GameObject>> m_gameObjects;
	std::vector<std::unique_ptr<GameObject>> m_newGameObjects; //New game objects to add upon new frame
};

#endif // !GAME_OBJECT_MANAGER_H