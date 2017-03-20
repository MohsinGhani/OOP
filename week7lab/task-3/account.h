#include <string>

using namespace std;
class Account{
private:
	int accNum;
	string name;
	int _balance;

public:
	Account(int, string, int);

	//getters
	int getAccountNum();
	string getName();
	int getBalance();
	//setters
	void setAccountNum(int);
	void setName(string);
	void setBalance(int);
	void Deposit( int);
	void Withdraw( int);
	void viewBalance();

};
