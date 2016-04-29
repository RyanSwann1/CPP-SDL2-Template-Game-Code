#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <string>
class GameState
{
public:
	GameState();
	~GameState();

	virtual void draw() = 0;
	virtual void update() = 0;
	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	std::string getID() const { return m_ID; }

protected:
	std::string m_ID;

private:

};
#endif // !GAME_STATE_H