#include "stdafx.h"
#include <iostream>
#include "Matrix.h"

using namespace std;


Matrix::Matrix(int matrix1[][10],int matrix2[][10],int size)
{
	_size = size;
	for(int i=0; i<_size; i++){
		for(int j=0; j<_size; j++){
			_matrix1[i][j] =  matrix1[i][j];
			_matrix2[i][j] =  matrix2[i][j];
		}
	}
}

int Matrix::addition(int rowIndex, int colIndex){
	int _addition[10][10];
	for(int i=0; i<_size; i++){
		for(int j=0; j<_size; j++){
			_addition[i][j] = _matrix1[i][j] + _matrix2[i][j];
		}
	}
	return _addition[rowIndex][colIndex];
}

int Matrix::subtraction(int rowIndex, int colIndex){
	int _subtraction[10][10];
	for(int i=0; i<_size; i++){
		for(int j=0; j<_size; j++){
			_subtraction[i][j] = _matrix1[i][j] - _matrix2[i][j];
		}
	}
	return _subtraction[rowIndex][colIndex];
}

int Matrix::scalarMultiplication(int rowIndex, int colIndex, int scalar){
	int _scalarMultiplication[10][10];
	for(int i=0; i<_size; i++){
		for(int j=0; j<_size; j++){
			_scalarMultiplication[i][j] = _matrix1[i][j] * scalar;
		}
	}
	return _scalarMultiplication[rowIndex][colIndex];
}

int Matrix::matrixMultiplication(int rowIndex, int colIndex){
	int _matrixMultiplication[10][10];
	for (int i = 0; i < _size; i++) {
            for (int j = 0; j < _size; j++) {
                _matrixMultiplication[i][j] = 0;
                for (int k = 0; k < _size; k++) {
					_matrixMultiplication[i][j] = _matrixMultiplication[i][j] + _matrix1[i][k] * _matrix2[k][j];
                }
            }
	}
	return _matrixMultiplication[rowIndex][colIndex];
}
