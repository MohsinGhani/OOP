#pragma once

// class definition of Time

class Time
{
	// data members
private:
	int _hour;
	int _minutes;
	int _seconds;
	int _milliseconds;

	// member functions
public:
	Time();
	Time(int hour, int minutes, int seconds, int milliseconds);

	// getters & setters
	int GetHour();
	void SetHour(int hour);
	int GetMinutes();
	void SetMinutes(int minutes);
	int GetSeconds();
	void SetSeconds(int seconds);
	int GetMilliseconds();
	void SetMilliseconds(int milliseconds);

	// operations
	bool anotherTime(int hour, int minutes, int seconds, int milliseconds);
	void addSeconds(int seconds);
	void printDate();

private:
	int GetDaysInMonth();
};
