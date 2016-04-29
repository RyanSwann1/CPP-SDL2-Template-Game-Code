#include "Game.h"
#include "TextureManager.h"
#include <assert.h>
#include <SDL_image.h>
#include <iostream>
#include <string>

Game * Game::sm_instance = new Game();

Game::Game()
{
	m_isRunning = true;
	m_playingFieldHeight = 0;
	m_playingFieldWidth = 0;
}

Game::~Game()
{
}

void Game::handleEvents()
{
	m_eventHandler.update();
}

void Game::update()
{
	m_gameStateMachine.update();
}

void Game::render()
{
	SDL_RenderClear(m_renderer.get());

	m_gameStateMachine.draw();

	SDL_RenderPresent(m_renderer.get());
}

bool Game::init(const char * title, const int w, const int h)
{
	SDL_Init(SDL_INIT_EVERYTHING); //init SDL VIDEO
	IMG_Init(IMG_INIT_PNG);

	//Initialize playing field bounds
	m_playingFieldHeight = h;
	m_playingFieldWidth = w;

	//Create Window
	m_window = std::unique_ptr<SDL_Window, sdldeleter>(SDL_CreateWindow(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, SDL_WINDOW_SHOWN));
	assert(m_window != nullptr);
	//GEt window surface
	m_windowSurface = std::unique_ptr<SDL_Surface, sdldeleter>(SDL_GetWindowSurface(m_window.get()));
	assert(m_windowSurface != nullptr);
	//Create renderer
	m_renderer = std::unique_ptr<SDL_Renderer, sdldeleter>(SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_PRESENTVSYNC)); 
	assert(m_renderer != nullptr);

	////Load in all textures
	m_textureManager.load("Textures/PlayerShip.PNG", "PlayerShip");
	m_textureManager.load("Textures/PlayerLaser.PNG", "PlayerLaser");
	m_textureManager.load("Textures/PlayIcon.PNG", "PlayIcon");
	m_textureManager.load("Textures/QuitIcon.PNG", "QuitIcon");

	//Init game state machine
	m_gameStateMachine.init();


	//IF init was successful
	return true;
}
