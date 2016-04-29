#include "Timer.h"
#include <iostream>


Timer::Timer()
{
	m_currentTime = 0;
}


Timer::~Timer()
{
}

void Timer::update()
{
	m_currentTime = SDL_GetTicks();
}

bool Timer::compareCurrentTime(const int i) const
{
	return SDL_TICKS_PASSED(m_currentTime, i);
}
