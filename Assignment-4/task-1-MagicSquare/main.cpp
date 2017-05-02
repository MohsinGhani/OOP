#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "MagicSquare.h"

using namespace std;

bool IsValidInput(int num)
{
	if (num < 3 || num > 19 || (num % 2 == 0))
		return false;
	return true;
}

int TakeInput()
{
	int result;
	cout << "Enter an odd number between 3 and 19: ";
	cin >> result;
	while (!IsValidInput(result))
	{
		cout << "Invalid input! Try again: ";
		cin >> result;
	}
	return result;
}

int main()
{
	// take an input between 3 and 19
	int input = TakeInput();
	MagicSquare square(input);
	square.GenerateSquare();
	// print square
	cout << "Magic square of size " << input << " is generated below.";
	cout << " Each row, column and diagonal sums to " << square.GetSum() << endl;
	for (int rowIndex = 0; rowIndex < input; ++rowIndex)
	{
		for (int colIndex = 0; colIndex < input; ++colIndex)
			cout << setw(4) << square.GetCellValue(rowIndex, colIndex);
		cout << endl;
	}
    return 0;
}

