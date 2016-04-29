#ifndef GAME_STATE_MACHINE_H
#define GAME_STATE_MACHINE_H

#include "GameState.h"
#include <vector>
#include <memory>
class GameStateMachine
{
public:
	GameStateMachine();
	~GameStateMachine();

	void init();
	void changeState(std::unique_ptr<GameState>& newGameState);
	void update() { m_gameStates.back()->update(); }
	void draw() { m_gameStates.back()->draw(); }

private:
	std::vector<std::unique_ptr<GameState>> m_gameStates;


};
#endif // !GAME_STATE_MACHINE_H
