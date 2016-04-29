#include "GameStateMachine.h"
#include "MenuState.h"


GameStateMachine::GameStateMachine()
{
}


GameStateMachine::~GameStateMachine()
{
}

void GameStateMachine::init()
{
	//Check to see whether it isempty beore initlaizatn
	if (m_gameStates.empty())
	{
		m_gameStates.push_back(std::unique_ptr<GameState>(new MenuState()));
		m_gameStates.back()->onEnter();
	}
}

void GameStateMachine::changeState(std::unique_ptr<GameState>& newGameState)
{
	if (!m_gameStates.empty())
	{
		if (newGameState.get()->getID() != m_gameStates.back()->getID())
		{
			m_gameStates.back()->onExit();
			m_gameStates.pop_back(); //Remove current state

			m_gameStates.emplace_back(std::unique_ptr<GameState>(std::move(newGameState))); //add new state
			m_gameStates.back()->onEnter();
		}
	}
}
