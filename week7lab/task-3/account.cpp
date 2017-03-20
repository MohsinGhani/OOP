#include "Account.h"
#include <string>
#include <iostream>

using namespace std;

Account::Account(int accountNum, string name, int balance)
{
	accNum = accountNum;
	name = name;
	_balance = balance;
}

int Account::getAccountNum(){
	return accNum;
};
string Account::getName(){
	return name;
};
int Account::getBalance(){
	return _balance;
};

void Account::setAccountNum(int number){
	accNum = number;
};

void Account::setName(string name){
	name = name;
};

void Account::setBalance(int balance){
	_balance = balance;
};

void Account::viewBalance(){
	cout << "Number: " << accNum << endl << "Name: " << name << endl << "Balance: " << _balance << endl;
}

void Account::Deposit( int money_to_deposit){
	_balance = _balance + money_to_deposit;
};

void Account::Withdraw(int money_to_withdraw){
	if(_balance < money_to_withdraw)
	{
		cout << "not done" << endl;
	}
	else{
	_balance -= money_to_withdraw;
	}
};
