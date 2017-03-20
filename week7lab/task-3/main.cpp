// task-3.cpp : Defines the entry point for the console application.
//

#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

int main()
{
	Account acc(140, "name" , 25000);
	acc.viewBalance();

	int cash;
	cout << "Deposit: ";
	cin >> cash;
	acc.Deposit(cash);
	acc.viewBalance();

	cout << "withdrow: ";
	cin >> cash;
	acc.Withdraw(cash);
	acc.viewBalance();
	return 0;
}

