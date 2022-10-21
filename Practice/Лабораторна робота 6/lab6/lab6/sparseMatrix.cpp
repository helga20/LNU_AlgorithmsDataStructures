#include "sparseMatrix.h"
#include <iostream>
using namespace std;

SparseMatrix::SparseMatrix()
{
	count = 0;
	size = 15;
	arr = new Data[size];
}

SparseMatrix::~SparseMatrix()
{
	delete[] arr;
}

void SparseMatrix::resize()
{
	Data* D = new Data[size];
	for (int i = 0; i < count; ++i)
	{
		D[i] = arr[i];
	}
	delete[] arr;
	arr = D;
}

int SparseMatrix::getCount()
{
	return count;
}

int SparseMatrix::getSize()
{
	return size;
}

int SparseMatrix::getValue(int rw, int clmn)
{
	for (int i = 0; i < count; ++i)
	{
		if (arr[i].row == rw && arr[i].colum == clmn)
		{
			return arr[i].value;
		}
	}
	cout << "\nSorry, value not found";
	return 0;
}

int SparseMatrix::getRows()
{
	if (isEmpty())
	{
		return count;
	}

	int max = arr[0].row;
	for (int i = 1; i < count; ++i)
	{
		if (arr[i].row > max)
		{
			max = arr[i].row;
		}
	}
	return max;
}

int SparseMatrix::getColums()
{
	if (isEmpty())
	{
		return count;
	}

	int max1 = arr[0].colum;
	for (int i = 1; i < count; ++i)
	{
		if (arr[i].colum > max1)
		{
			max1 = arr[i].colum;
		}
	}
	return max1;
}

bool SparseMatrix::findData(int rw, int clmn)
{
	for (int i = 0; i < count; ++i)
	{
		if (arr[i].colum == clmn && arr[i].row == rw)
		{
			return true;
		}
	}
	return false;
}

bool SparseMatrix::isEmpty()
{
	return (count == 0);
}

void SparseMatrix::printSparseMatrix()
{
	for (int i = 0; i < getRows(); ++i)
	{
		for (int j = 0; j < getColums(); ++j)
		{
			if (findData(i + 1, j + 1))
			{
				cout << " " << getValue(i + 1, j + 1) << " ";
			}
			else
			{
				cout << " 0 ";
			}
		}
		cout << "\n";
	}
}

void SparseMatrix::addData(int rw, int clmn, int val)
{
	if (findData(rw, clmn) || val == 0 || rw <= 0 || clmn <= 0)
	{
		cout << "\nError! Data cannot be 0 (maybe this data already exists)";
		return;
	}

	if (size <= count)
	{
		size *= 2;
		resize();
	}
	arr[count].row = rw;
	arr[count].colum = clmn;
	arr[count].value = val;
	++count;
}

void SparseMatrix::removeData(int rw, int clmn)
{
	if (!isEmpty())
	{
		for (int i = 0; i < count; ++i)
		{
			if (findData(rw, clmn))
			{
				--count;
				for (int j = i; j < count; ++j)
				{
					arr[j] = arr[j + 1];
				}
			}
		}
		return;
	}
	else
	{
		cout << "\nSorry, matrix is empty";
		return;
	}
}

void SparseMatrix::changeElementInSparceMatrix(int rw, int clmn, int val)
{
	if (findData(rw, clmn))
	{
		removeData(rw, clmn);
	}
	addData(rw, clmn, val);
}

void SparseMatrix::transposeSparseMatrix()
{
	if (!isEmpty())
	{
		for (int i = 0; i < count; ++i)
		{
			swap(arr[i].row, arr[i].colum);
		}
	}
	else
	{
		cout << "\nSorry, matrix is empty";
		return;
	}
}

