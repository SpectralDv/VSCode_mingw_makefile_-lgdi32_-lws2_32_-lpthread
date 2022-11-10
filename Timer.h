#pragma once
#ifndef _TIMER_H_
#define _TIMER_H_

#include <iostream>
#include <time.h>

using namespace std;

namespace SpaceTimer
{
	class Timer
	{
	public:
		Timer();
		~Timer();
		void ResetTimer();
		int GetTimer(int milisTimer);
	private:
		long futTime = 0;
		bool eventReset = false;
		bool eventStart = true;
	};
}


#endif