class Matrix
{
private:
	int _matrix1[10][10];
	int _matrix2[10][10];
	int _size;

public:
	Matrix(int matrix1[][10],int matrix2[][10],int size);
	int addition(int rowIndex, int colIndex);
	int subtraction(int rowIndex, int colIndex);
	int scalarMultiplication(int rowIndex, int colIndex, int scalar);
	int matrixMultiplication(int rowIndex, int colIndex);
};
