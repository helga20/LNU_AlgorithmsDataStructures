#pragma once
#include <iostream>
using namespace std;

class SparseMatrix
{
private:
	struct Data
	{
		int row;
		int colum;
		int value;
	};

	int size;
	int count;
	Data* arr;

public:
	SparseMatrix();
	~SparseMatrix();

	void resize();

	int getCount();
	int getSize();
	int getValue(int rw, int clmn);
	int getRows();
	int getColums();

	bool findData(int rw, int clmn);
	bool isEmpty();

	void printSparseMatrix();
	void addData(int rw, int clmn, int val);
	void removeData(int rw, int clmn);
	void changeElementInSparceMatrix(int rw, int clmn, int val);
	void transposeSparseMatrix();

};


