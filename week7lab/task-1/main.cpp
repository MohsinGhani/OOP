#include "Date.h"
#include<iostream>
using namespace std;

int main()
{
	Date date; //creating and object will directly call the default constructor
	date.printDate(); //printing default date

	Date newDate(14, 3, 2017); //creating object by passing value to overridden constructor
	newDate.printDate(); //printing custom date

	date.setDay(15); //changing day to 15
	date.setMonth(12); // changing day to 12
	date.setYear(2016); // changing year to 2016
	date.printDate(); // printing the changed date

	//cout << newDate.day << endl; //Error: Will not access private variable date
	cout << newDate.getDay() << endl; // Will print the day through calling get function
	cout << newDate.isEqual(newDate) << endl;

	short day,sday;

	cout << "Add days: ";
	cin >> day;
	date.addDays(day);
	date.printDate();

	cout << "Subtract days: ";
	cin >> sday;
	date.subDays(sday);
	cout << "After Subtract Days: ";
	date.printDate();
	return 0;
}
