#include <iostream>
using namespace std;
const int ROWS = 3;
const int COLS = 5; 
void MatrixFill(double arr[ROWS][COLS], const int ROWS, const int COLS);
void MatrixPrint(double arr[ROWS][COLS], const int ROWS, const int COLS);
double MatrixDefine(double arr[ROWS][COLS], const int ROWS, const int COLS);
void ReverseMatrix(double arr[ROWS][COLS], const int ROWS, const int COLS);
void main()
{
	double arr[ROWS][COLS];
	int result = 0;
	MatrixFill(arr, ROWS, COLS);
	cout << "Extended Matrix is: \n";MatrixPrint(arr, ROWS, COLS);
	cout << "Matrix Define is: \n"<< MatrixDefine(arr, ROWS, COLS);
	ReverseMatrix(arr, ROWS, COLS);
}
void MatrixFill(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 10;
			if (j == 3)
			{
				arr[i][j] = arr[i][0];
			}
			if (j == 4)
			{
				arr[i][j] = arr[i][1];
			}
		}
	}
}
void MatrixPrint(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}
double MatrixDefine(double arr[ROWS][COLS], const int ROWS, const int COLS)
{
	double MatrixDefine = 0;
	int result = 0;
	int arr2[6];
	for (int i = 0; i < ROWS; i++)
	{
		result = 0;
		result = arr[0][i] * arr[1][i + 1] * arr[2][i + 2];
		arr2[i] = result;
	}
	for (int i = 5; i > 2; i--)
	{
		result = 0;
		result = arr[0][i - 1] * arr[1][i - 2] * arr[2][i - 3];
		arr2[i] = result;
	}
	for (int i = 0; i < 6; i++)
	{
		if (i < 3)
		{
			MatrixDefine += arr2[i];
		}
		if (i >= 3)
		{
			MatrixDefine -= arr2[i];
		}
	}
	return MatrixDefine;
}
void ReverseMatrix(double arr[ROWS][COLS], const int ROWS, const int COLS) 
{
	double allyMatrix[3][3];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS - 2; j++)
		{
			if (i == 0 && j == 0)
			{
				allyMatrix[i][j] = arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1];
			}
			if (i == 0 && j == 1)
			{
				allyMatrix[i][j] = -(arr[0][1] * arr[2][2] - arr[0][2] * arr[2][1]);
			}
			if (i == 0 && j == 2)
			{
				allyMatrix[i][j] = arr[0][1] * arr[1][2] - arr[0][2] * arr[1][1];
			}
			if (i == 1 && j == 0)
			{
				allyMatrix[i][j] = -(arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0]);
			}
			if (i == 1 && j == 1)
			{
				allyMatrix[i][j] = arr[0][0] * arr[2][2] - arr[0][2] * arr[2][0];
			}
			if (i == 1 && j == 2)
			{
				allyMatrix[i][j] = -(arr[0][0] * arr[1][2] - arr[0][2] * arr[1][0]);
			}
			if (i == 2 && j == 0)
			{
				allyMatrix[i][j] = arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0];
			}
			if (i == 2 && j == 1)
			{
				allyMatrix[i][j] = -(arr[0][0] * arr[2][1] - arr[0][1] * arr[2][0]);
			}
			if (i == 2 && j == 2)
			{
				allyMatrix[i][j] = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
			}
		}
	}cout << endl;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS-2; j++)
		{
			cout << allyMatrix[i][j]<<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS-2; j++)
		{
			allyMatrix[i][j]*= (1/MatrixDefine(arr, ROWS, COLS));
			cout << allyMatrix[i][j]<<"\t";
		}
		cout << endl;
	}
}