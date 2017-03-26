#include "stdafx.h"
#include "date.h"
#include <iostream>

using namespace std;

int main()
{
	Date myDate(10, 2, 2017);

	cout << "Is " << myDate.GetDay() << "-" << myDate.GetMonth() << "-" << myDate.GetYear() << " a valid date: " << myDate.IsValidDate() << endl;

	int addDays;
	cout << "add days: ";
	cin >> addDays;
	myDate.addDays(addDays);
	cout << "After Add Days: " << myDate.GetDay() << "-" << myDate.GetMonth() << "-" << myDate.GetYear() << " a valid date: " << myDate.IsValidDate() << endl;

	int subDays;
	cout << "subtract days: ";
	cin >> subDays;
	myDate.subtractDays(subDays);
	cout << "After Subtraction Days: " << myDate.GetDay() << "-" << myDate.GetMonth() << "-" << myDate.GetYear() << " a valid date: " << myDate.IsValidDate() << endl;
	return 0;
}

