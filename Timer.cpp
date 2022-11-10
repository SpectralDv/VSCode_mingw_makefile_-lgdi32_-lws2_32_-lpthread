
#include "Timer.h"


namespace SpaceTimer
{
	Timer::Timer() {}
	Timer::~Timer() { printf("~Timer"); }
	void Timer::ResetTimer()
	{
		eventReset = true;
	}
	int Timer::GetTimer(int milisTime)
	{
		if (eventStart == true)
		{
			eventStart = false;
			futTime = clock() + milisTime;
		}
		if (eventReset == true)
		{
			eventReset = false;
			eventStart = true;
		}
		if ((clock() > futTime))
		{
			eventStart = true;
			futTime = clock() + milisTime;
			return 1;
		}
		return 0;
	}
}