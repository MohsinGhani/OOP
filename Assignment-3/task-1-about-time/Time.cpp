// implementation file of Time Class

#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include  <iomanip>
using namespace std;

Time::Time() // no argument constructor
{
	// default Time is 12:00
	_hour = 12;
	_minutes = 00;
	_seconds = 00;
	_milliseconds = 0000;
}

//four argument constructor
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
	//if the time is less than or equal to the time stored in the argument than it return true
	if(_hour <= hour){
		_hour = hour;
		_minutes = minutes;
		_seconds = seconds;
		_milliseconds = milliseconds;
		return true;
	}
	_hour = hour;
	_minutes = minutes;
	_seconds = seconds;
	_milliseconds = milliseconds;
	return false;
}

void Time::addSeconds(int seconds)
{
	//add seconds
	_seconds +=seconds;
		//if seconds are greater than 59 then this loop increament 1 in minutes until se seconds are less than 59
		while(_seconds>59)
		{
			_seconds -= 60;
			_minutes++;
		}
		//if minutes are greater than 59 then this loop increament 1 in hour until se minutes are less than 59
		while(_minutes>59){
			_minutes -= 60;
			_hour++;
		}
		
};

void Time::printTime(){
	//this statement print time but whitout AM PM
	//cout << setw(2)  << setfill('0') << _hour << ":" << setw(2)  << setfill('0') << _minutes << ":"  << setw(2)  << setfill('0') << _seconds << ":"  << setw(4)  << setfill('0') << _milliseconds << endl;
	
	//Determine AM or PM condition and also validate the time if time is less than 0 and greater than 24 then it print invalid time
	if(_hour >= 12 && _hour <= 24)
	{
		_hour -=12;
		cout << setw(2)  << setfill('0') << _hour << ":" << setw(2)  << setfill('0') << _minutes << ":"  << setw(2)  << setfill('0') << _seconds << " PM" << endl;
	}
	else if(_hour <= 12 && _hour >= 0){
		cout << setw(2)  << setfill('0') << _hour << ":" << setw(2)  << setfill('0') << _minutes << ":"  << setw(2)  << setfill('0') << _seconds << " AM" << endl;
	}
	else
	{
		cout << "ERR! Invalid time, after addition Hours is greater than 24";
	}
}
