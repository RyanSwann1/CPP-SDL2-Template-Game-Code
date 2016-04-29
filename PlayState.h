#ifndef PLAY_STATE_H
#define PLAY_STATE_H

#include "GameState.h"
#include "GameObjectManager.h"
#include <vector>
#include <memory>
class PlayState :
	public GameState
{
public:
	PlayState();
	~PlayState();

	void update() override;
	void draw() override;
	void onEnter() override;
	void onExit() override;

private:

};
#endif // !PLAY_STATE_H