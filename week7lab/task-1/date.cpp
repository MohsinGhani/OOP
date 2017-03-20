#include "Date.h"
#include <iostream>

using namespace std;

Date::Date()
{
	day = 1;
	month = 1;
	year = 2000;
}

Date::Date(short d, short m, short y)
{
	day = d;
	month = m;
	year = y;
}

short Date::getDay(){
	return day;
}

short Date::getMonth(){
	return month;
}

short Date::getYear(){
	return year;
}

void Date::setDay(short d){
	day = d;
}

void Date::setMonth(short m){
	month = m;
}

void Date::setYear(short y){
	year = y;
}

bool Date::isLeapYear(){
	if (year % 400 == 0)
		return true;
	if (year % 4 == 0 && year % 100 != 0)
		return true;
	return false;
}

short Date::GetDaysInMonth(){
	int DaysInMonths[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (isLeapYear() && month == 2)
		return DaysInMonths[month - 1] + 1;
	return DaysInMonths[month - 1];
}
bool Date::IsValidDate(){
	if (month < 1 || month > 12)
		return false;
	if (year < 1)
		return false;
	if (day < 1 || day > GetDaysInMonth())
		return false;
	return true;
}


void Date::printDate(){
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::isEqual(Date date)
{
	if (day == date.getDay() && month == date.getMonth() && year == date.getYear())
	{
		return true;
	}
	return false;
}

void Date::addDays(short numbers){
	day = day + numbers;
	int dayInMonth = GetDaysInMonth();
	for(int i=0; i<=day-dayInMonth; i++)
	{
		day -= dayInMonth;
		month++;
		if (month > 12){
			month -= 12;
			year++;
		}
	}
	
}

void Date::subDays(short numbers){
	day = day - numbers;
	int dayInMonth = GetDaysInMonth();
	if(day <= 0){
		for(;day<=0;){
			day += dayInMonth;
			month--;
		}
	}
	if (month <= 0)
	{
		month +=12;
		year--;
	}
}
