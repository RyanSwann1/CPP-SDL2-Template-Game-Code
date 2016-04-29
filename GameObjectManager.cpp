#include "GameObjectManager.h"
#include <iterator>
#include <iostream>

GameObjectManager::GameObjectManager()
{
}


GameObjectManager::~GameObjectManager()
{
}

void GameObjectManager::draw()
{
	for(auto &gameObject : m_gameObjects)
	{ 
		gameObject->draw();
	}
}

void GameObjectManager::update()
{
	for (auto &gameObject : m_gameObjects)
	{
		gameObject->update();
	}

	//After loop, add all newly added gameobjects that were added in the loop into the m_gameObjects vector so it doesn't bug#
	std::move(m_newGameObjects.begin(), m_newGameObjects.end(), std::back_inserter(m_gameObjects));
	m_newGameObjects.clear();


	//PREVIOUSLY TRIED METHODS
	//std::vector<std::unique_ptr<GameObject>>::const_iterator cIter;
	//for (cIter == m_newGameObjects.cbegin(); cIter != m_newGameObjects.cend(); cIter++)
	//{
	//	GameObject *gameObject = std::move(*cIter);
	//	std::unique_ptr<GameObject> gameObject(std::move(cIter));		
	//	m_gameObjects.emplace_back(std::move(cIter));
	//}
	//m_gameObjects.insert(std::end(m_gameObjects), std::begin(std::move(m_newGameObjects)), std::end(std::move(m_newGameObjects))); //Insert new game objects
}