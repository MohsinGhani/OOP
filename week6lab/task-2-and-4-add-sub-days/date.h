#pragma once

// class definition of Date

class Date
{
	// data members
private:
	int _day;
	int _month;
	int _year;

	// member functions
public:
	Date();
	Date(int day, int month, int year);

	// getters & setters
	int GetDay();
	void SetDay(int day);
	int GetMonth();
	void SetMonth(int month);
	int GetYear();
	void SetYear(int year);

	// operations
	bool IsValidDate();
	bool IsLeapYear();
	void addDays(int addDays);
	void subtractDays(int subDays);

private:
	int GetDaysInMonth();
};
