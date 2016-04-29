#ifndef TIMER_H
#define TIMER_H

#include <SDL.h>
class Timer
{
public:
	Timer();
	~Timer();

	void update();
	bool compareCurrentTime(const int i) const;
	Uint32 getTimer() { return m_currentTime; }
private:
	Uint32 m_currentTime;
};
#endif // !TIMER_H
