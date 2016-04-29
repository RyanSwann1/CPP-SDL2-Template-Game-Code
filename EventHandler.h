#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Vector2.h"
#include <SDL.h>
#include <vector>

class EventHandler
{
	enum MouseBottons
	{
		LEFT,
		RIGHT,
		TOTAL_BUTTONS
	};
public:
	EventHandler();
	~EventHandler();

	void update();
	bool isKeyDown(const SDL_Scancode key) { return m_keyStates[key] == 1; }
	bool isMouseButtonDown(const int button) { return m_mouseButtonStates[button]; }
	int getLeftButton() const { return LEFT; }
	int getRightButton() const { return RIGHT; }
	Vector2 getMousePosition() const { return m_mousePosition; }

private:
	Vector2 m_mousePosition;
	std::vector<bool> m_mouseButtonStates;
	SDL_Event e;
	const Uint8* m_keyStates;

	void onMouseButtonDown();
	void onMouseButtonUp();
	void onMouseMotion();

};
#endif // !EVENT_HANDLER_H
