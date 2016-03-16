/*
 * Timer.cpp
 *
 *  Created on: Feb 16, 2016
 *      Author: rbak9218
 */
#include <iostream>
#include <iomanip>
#include "Timer.h"
using namespace std;

Timer::Timer()
{
	executionTime = 0;
}

Timer::~Timer()
{
	// TODO Auto-generated destructor stub
}

void Timer::displayTimerInformation()
{
	cout << fixed;
	cout << setprecision(8);

	cout << executionTime << " us (microseconds) for the code " << endl;
	cout << "Which is " << float(executionTime)/CLOCKS_PER_SEC<< " seconds" << endl;
}

void Timer::startTimer()
{
	executionTime = clock();
}

void Timer::stopTimer()
{
	executionTime = clock() - executionTime;
}

void Timer::resetTimer()
{
	executionTime = 0;
}

long Timer::getExecutionTimeInMicroseconds()
{
	return executionTime;
}
