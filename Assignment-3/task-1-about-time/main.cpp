// task-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Time.h"
#include <iostream>
#include  <iomanip>

using namespace std;

int main()
{
	Time newTime(12,00,00,0000);
	int hour, minutes, seconds, milliseconds;
	//print time using getters
	cout << "Default Time: " << setw(2)  << setfill('0') << newTime.GetHour() << ":" << setw(2)  << setfill('0') <<  newTime.GetMinutes() << ":"  << setw(2)  << setfill('0') <<   newTime.GetSeconds() << ":"  << setw(4)  << setfill('0') <<   newTime.GetMilliseconds() << endl;
	//newTime.printTime();
	
	char temp;
	cout << "Enter another Time <hh:mm:ss:ff> : ";
	cin >> hour >> temp >> minutes >> temp  >> seconds >> temp  >> milliseconds;
	while(hour > 24){
		cout << "ERR! Your input hours are not valid please input less than 24 hour\n";
		cout << "Enter another Time <hh:mm:ss:ff> : ";
		cin >> hour >> temp >> minutes >> temp  >> seconds >> temp  >> milliseconds;
	}
	cout << "Default time is less than or equal to the input time: " << newTime.anotherTime(hour, minutes, seconds, milliseconds) << endl;
	cout << "add seconds: ";
	cin >> seconds;
	newTime.addSeconds(seconds);
	newTime.printTime();
	
	return 0;
}
