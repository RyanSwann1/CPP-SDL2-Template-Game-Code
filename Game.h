#ifndef GAME_H
#define GAME_H

#include "GameStateMachine.h"
#include "sdldeleter.h"
#include "GameObjectManager.h"
#include "TextureManager.h"
#include "EventHandler.h"
#include "Timer.h"
#include "CollisionManager.h"
#include "IconManager.h"
#include <SDL.h>
#include <memory>
#include <vector>
class Game
{
public:


	static Game *instance() { return sm_instance; }
	void handleEvents();
	void update();
	void render();

	bool init(const char* title, const int w, const int h);
	bool isRunning() const { return m_isRunning; }

	void end() { m_isRunning = false; }

	//Getters
	int getPlayingFieldWidth() const { return m_playingFieldWidth; }
	int getPlayingFieldHeight() const { return m_playingFieldHeight; }
	SDL_Renderer* getRenderer() const { return m_renderer.get(); }
	SDL_Surface* getWindowSurface() const { return m_windowSurface.get(); }
	
	TextureManager& getTextureManager() { return m_textureManager; }
	GameObjectManager& getGameObjectManager() { return m_gameObjectManager; }
	IconManager& getIconManager() { return m_iconManager; }
	Timer& getTimer() {return m_timer; } //Question why I had to return this as a reference
	GameStateMachine& getGameStateMachine() { return m_gameStateMachine; }
	EventHandler getEventHandler() const { return m_eventHandler; }
	CollisionManager getCollisionManager() const { return m_collisionManager; }



private:

	Game();
	~Game();
	//Size of playing field/game window
	unsigned int m_playingFieldWidth;
	unsigned int m_playingFieldHeight;
	bool m_isRunning; //Is game running
	static Game* sm_instance;
	std::unique_ptr<SDL_Window, sdldeleter> m_window; //SDL WIndow
	std::unique_ptr<SDL_Renderer, sdldeleter> m_renderer; //SDL Renderer
	std::unique_ptr<SDL_Surface, sdldeleter> m_windowSurface; //SDL Surface of the window

	//Timer
	Timer m_timer;
	//Event handler
	EventHandler m_eventHandler;
	//Collision Handler
	CollisionManager m_collisionManager;
	//Managers
	IconManager m_iconManager;
	TextureManager m_textureManager;
	GameObjectManager m_gameObjectManager;
	//Game state machine
	GameStateMachine m_gameStateMachine;
};
#endif // !GAME_H