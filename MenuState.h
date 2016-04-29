#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameState.h"
class MenuState :
	public GameState
{
public:
	MenuState();
	~MenuState();

	void draw() override;
	void update() override;
	void onEnter() override;
	void onExit() override;

private:

};
#endif // !MENU_STATE_H
