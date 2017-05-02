#pragma once
class MagicSquare
{
private:
	int _data[19][19];
	int _size;
public:
	MagicSquare(int size);
	~MagicSquare();
	void GenerateSquare();
	int GetCellValue(int rIndex, int cIndex);
	int GetSum();
};

