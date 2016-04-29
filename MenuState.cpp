#include "MenuState.h"
#include "Game.h"
#include "MenuIcon.h"
#include <memory>

MenuState::MenuState()
{
}


MenuState::~MenuState()
{
}

void MenuState::draw()
{
	Game::instance()->getIconManager().draw();
}

void MenuState::update()
{
	Game::instance()->getIconManager().update();
}

void MenuState::onEnter()
{
	Game::instance()->getIconManager().addIcon(std::unique_ptr<Icon>(new MenuIcon(300, 150, 90, 30, "PlayIcon")));
	Game::instance()->getIconManager().addIcon(std::unique_ptr<Icon>(new MenuIcon(300, 250, 90, 30, "QuitIcon")));
}

void MenuState::onExit()
{
	//Erase all game objects for when entering the play state
	//Game::instance()->getIconManager().clearIcons();
	
}
