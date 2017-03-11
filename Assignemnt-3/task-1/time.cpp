// implementation file of Time Class

#include "stdafx.h"
#include "Time.h"
#include <iostream>
using namespace std;

Time::Time()
{
	// default Time is 12:00
	_hour = 12;
	_minutes = 00;
	_seconds = 00;
	_milliseconds = 0000;
}

Time::Time(int hour, int minutes, int seconds, int milliseconds)
{
	_hour = hour;
	_minutes = minutes;
	_seconds = seconds;
	_milliseconds = milliseconds;
}

int Time::GetHour()
{
	return _hour;
}

void Time::SetHour(int hour)
{
	_hour = hour;
}

int Time::GetMinutes()
{
	return _minutes;
}

void Time::SetMinutes(int minutes)
{
	_minutes = minutes;
}

int Time::GetSeconds()
{
	return _seconds;
}

void Time::SetSeconds(int seconds)
{
	_seconds = seconds;
}

int Time::GetMilliseconds()
{
	return _milliseconds;
}

void Time::SetMilliseconds(int milliseconds)
{
	_milliseconds = milliseconds;
}

bool Time::anotherTime(int hour, int minutes, int seconds, int milliseconds)
{
	if(_hour<=hour){
		return true;
	}
	return false;
}

void Time::addSeconds(int seconds)
{
	_seconds +=seconds;
		while(_seconds>59)
		{
			_seconds -= 60;
			_minutes++;
		}
		while(_minutes>59){
			_minutes -= 60;
			_hour++;
		}
};
