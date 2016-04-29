#include "PlayState.h"
#include "Player.h"
#include "Game.h"
#include "PlayerLaser.h"
#include <iostream>
PlayState::PlayState()
{
	m_ID = "PlayState";
}


PlayState::~PlayState()
{
}

void PlayState::draw()
{
	Game::instance()->getGameObjectManager().draw();
}

void PlayState::update()
{
	Game::instance()->getGameObjectManager().update(); //Update game objects
	Game::instance()->getTimer().update(); //Update timer
}

void PlayState::onEnter()
{
	Game::instance()->getGameObjectManager().initGameObject(std::unique_ptr<GameObject>(new Player()));
	//Game::instance()->getGameObjectManager().addGameObject(std::unique_ptr<GameObject>(new PlayerLaser(100, 25)));
}

void PlayState::onExit()
{

}
