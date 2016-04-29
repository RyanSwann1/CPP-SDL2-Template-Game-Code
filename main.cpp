#include "Game.h"
#include <iostream>
#include <memory>
#include <vector>
#include <string>


int main(int argc, char* args[])
{
	Game &game = *Game::instance();
	//Init game
	if (game.init("Aliens Attack", 700, 400))
	{
		//
		while (game.isRunning())
		{
			game.handleEvents();
			game.update();
			game.render();
		}
	}
	else
	{
		std::cout << "Game failed to initialize.\n";
		return -1;
	}
	return 0;

	//Empalce back transfers ownership


}




//void load() { m_gameObjects.push_back }
//Projectile *laser = new Projectile("rawr");
//laser.m_positionX = 2; // blahhh


/*
void PlayerManager::shoot()
{
if (m_fireLaser = true)
{

Projectile *laser = new Projectile("rawr");
laser.m_positionX = 2; // blahhh
Javawag: then m_gameObjectManager.load(laser);
Javawag: but yes, yes it can : D
BonBons : ohhhh
BonBons : oh shit
Javawag : although dont you do that in your gamestate ? so that when you change state the objects are all removed ?
BonBons : yeh
Javawag : so you might not need a separate manager : O
BonBons : oh soi can just say laser.m_startPosition->().DOT.bracket(). < inert this.m_position.x


m_gameObjectManager->load(new Player()); //The position of player is already defined already in the player class
//so theres no need to send in anything as an arguement
m_gameObjectManager->load(new Projectile("I need to send in the spawn position") // But here i need to somehow send in the position of the spawn
//There will be a conflict of arguments too - OR WILL THER EBECAUSE ITS GOING OF THE CONSTRUCTOR FROM THE PROJECTILE?!?!?


m_playerLaserManager->load()
/*	m_playerLaserManager->load();
m_playerLaserManager->*/
	//}
