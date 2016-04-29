#include "EventHandler.h"
#include "Game.h"


EventHandler::EventHandler()
{
	//Initialize the key state
	m_keyStates = SDL_GetKeyboardState(nullptr);

	//Initialize the mouse button states IE Pressed buttons
	for (unsigned int i = 0; i < TOTAL_BUTTONS; i++)
	{
		m_mouseButtonStates.push_back(false);
	}
	m_mousePosition.setX(0);
	m_mousePosition.setY(0);
}


EventHandler::~EventHandler()
{
}

void EventHandler::update()
{
	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT: Game::instance()->end(); break;
		case SDL_MOUSEBUTTONDOWN: onMouseButtonDown(); break;
		case SDL_MOUSEBUTTONUP: onMouseButtonUp(); break;
		case SDL_MOUSEMOTION: onMouseMotion(); break;
		}
	}
}

void EventHandler::onMouseButtonDown()
{
	//If left click pressed
	if (e.button.button == SDL_BUTTON_LEFT) {
		m_mouseButtonStates[LEFT] = true;
	}

	else if (e.button.button == SDL_BUTTON_RIGHT) {
		m_mouseButtonStates[RIGHT] = true;
	}

}

void EventHandler::onMouseButtonUp()
{
	//Reset all mouse button states
	std::vector<bool>::iterator iter;
	for (iter = m_mouseButtonStates.begin(); iter != m_mouseButtonStates.end(); iter++)
	{
		*iter = false;
	}
}

void EventHandler::onMouseMotion()
{
	m_mousePosition.setX(e.motion.x);
	m_mousePosition.setY(e.motion.y);
}
