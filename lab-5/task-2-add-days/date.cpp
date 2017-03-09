
// implementation file of Date Class

#include "stdafx.h"
#include "date.h"

Date::Date()
{
	// default date is 1st Jan 2000
	_day = 1;
	_month = 1;
	_year = 2000;
}

Date::Date(int day, int month, int year)
{
	_day = day;
	_month = month;
	_year = year;
}


int Date::GetDay()
{
	return _day;
}

void Date::SetDay(int day)
{
	_day = day;
}

int Date::GetMonth()
{
	return _month;
}

void Date::SetMonth(int month)
{
	_month = month;
}

int Date::GetYear()
{
	return _year;
}

void Date::SetYear(int year)
{
	_year = year;
}

bool Date::IsValidDate()
{
	if (_month < 1 || _month > 12)
		return false;
	if (_year < 1)
		return false;
	if (_day < 1 || _day > GetDaysInMonth())
		return false;

	return true;
}

int Date::GetDaysInMonth()
{
	static int days[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (_month == 2 && IsLeapYear())
		return 29;
	return days[_month];
}


bool Date::IsLeapYear()
{
	// return true if it is fully divisible by 400
	// OR if it is fully divisible by 4 BUT does not fall at the end of the century
	return(_year % 400 == 0 || _year % 4 == 0 && _year % 100 != 0);
}


void Date::addDays(int addDays){
	_day = _day + addDays;
	int limitDay = GetDaysInMonth();
	if (_day > limitDay){
		_day = _day - limitDay;
		_month++;
	}
	if (_month > 12){											
		_month = _month - 12;
		_year++;
	}
}
