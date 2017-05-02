#include "stdafx.h"
#include "MagicSquare.h"


MagicSquare::MagicSquare(int size)
{
	_size = size;
	// initialize square
	for (int rIndex = 0; rIndex < size; ++rIndex)
		for (int cIndex = 0; cIndex < size; ++cIndex)
			_data[rIndex][cIndex] = 0;
}

void MagicSquare::GenerateSquare()
{
    _data[0][_size/2] = 1; // assign the value at middle index e.g 3x3 matrix at index 0 "1" 2
    int limit = _size*_size;

    int currentRow = 0;
    int currentCol = _size/2;
    int index,nextRow,nextCol;

    for(index=2; index<=limit; index++)
    {
        if((currentCol+1)>(_size-1)) {
            nextCol = 0;
        }
        else {
            nextCol = currentCol+1;
        }
		if((currentRow-1)<0) {
            nextRow = _size-1;
        }
        else
        {
            nextRow = currentRow-1;
        }

        if(_data[nextRow][nextCol]>0)
        {
            if((currentRow+1)>(_size-1))
            {
                nextRow = 0;
            }
            else
            {
                nextRow = currentRow+1;
                nextCol = currentCol;
            }
        }

        currentRow = nextRow;
        currentCol = nextCol;
        _data[currentRow][currentCol] = index;
    }
}

int MagicSquare::GetCellValue(int rIndex, int cIndex)
{
	if (rIndex < 0 || rIndex >= _size)
		return -1;
	if (cIndex < 0 || cIndex >= _size)
		return -1;

	return _data[rIndex][cIndex];
}

int MagicSquare::GetSum()
{
	int sum = 0;
	for (int rowIndex = 0; rowIndex < _size; ++rowIndex) {
			sum += _data[0][rowIndex];
	}
	return sum;
}

MagicSquare::~MagicSquare()
{
}
