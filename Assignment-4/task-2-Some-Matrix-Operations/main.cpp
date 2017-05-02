// task-2-matrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "Matrix.h"

using namespace std;

int matrix1[10][10],matrix2[10][10], scalar;;
void takeInput(int size, int choise);
void printMatrix(int choise, int size);

int _tmain(int argc, _TCHAR* argv[])
{
	int size, choise;
	Home:
	cout << "\t----------------------------------" << endl;
	cout << "\t  ** ASSIGNMENT#4 QUESTION#2 **" << endl;
	cout << "\t----------------------------------" << endl;
	cout << "\tPress 1 for Matrix Addition." << endl ;
	cout << "\tPress 2 for Matrix Subtraction." << endl ;
	cout << "\tPress 3 for Matrix Multiplication." << endl ;
	cout << "\tPress 4 for Scalar Multiplication." << endl ;

	cout << "\tChose the following Number: ";
	cin >> choise;

	if(choise > 0 && choise < 5){
		cout << "Enter the size of Matrix: ";
		cin >> size;
		takeInput(size, choise);
		printMatrix(choise,size);
		goto Exit;
	}
	else {
		cout << "Please Enter the Valid Input..." << endl;
		goto Exit;
	}

Exit:
	char exit = 'N';
	cout << "Do You Want to Continue? (Y/N): ";
	cin >> exit;
	if(!(exit == 'N' || exit == 'n')){
		system("cls");
		goto Home;
	}
	return 0;
}

void takeInput(int size, int choise){
	cout << "Enter values for first Matrix: " << endl;
		for(int i=0; i<size; i++){
			for(int j=0; j<size; j++){
				cout << "First Matrix[" << i+1 << "][" << j+1 << "]: ";
				cin >> matrix1[i][j];
			}
		}
		if(!(choise == 4)){
			cout << "Enter values for second Matrix: " << endl;
			for(int i=0; i<size; i++){
				for(int j=0; j<size; j++){
					cout << "Second Matrix[" << i+1 << "][" << j+1 << "]: ";
					cin >> matrix2[i][j];
				}
			}
		}
		if(choise == 4){
			cout << "Enter the scalar number: ";
			cin >> scalar;
		}
}

void printMatrix(int choise, int size){
	Matrix matrix(matrix1,matrix2,size);
	if(choise == 1){
		cout << "Addition of Matrix: " << endl;
		for (int rowIndex = 0; rowIndex < size; ++rowIndex)
		{
			for (int colIndex = 0; colIndex < size; ++colIndex)
				cout << setw(4) << matrix.addition(rowIndex, colIndex);
			cout << endl;
		}
	} else if(choise == 2){
		cout << "Subtraction of Matrix: " << endl;
		for (int rowIndex = 0; rowIndex < size; ++rowIndex)
		{
			for (int colIndex = 0; colIndex < size; ++colIndex)
				cout << setw(4) << matrix.subtraction(rowIndex, colIndex);
			cout << endl;
		}
	} else if(choise == 3){
		cout << "Multiplication of Matrix: " << endl;
		for (int rowIndex = 0; rowIndex < size; ++rowIndex)
		{
			for (int colIndex = 0; colIndex < size; ++colIndex)
				cout << setw(4) << matrix.matrixMultiplication(rowIndex, colIndex);
			cout << endl;
		}
	} else if(choise == 4){
		cout << "Scalar Multiplication of Matrix: " << endl;
		for (int rowIndex = 0; rowIndex < size; ++rowIndex)
		{
			for (int colIndex = 0; colIndex < size; ++colIndex)
				cout << setw(4) << matrix.scalarMultiplication(rowIndex, colIndex,scalar);
			cout << endl;
		}
	}
}



