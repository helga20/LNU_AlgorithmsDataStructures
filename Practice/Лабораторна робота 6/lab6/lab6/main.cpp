#include<iostream>
#include "sparseMatrix.h"
using namespace std;

int main()
{
	SparseMatrix SM;

	cout << "\nSparse matrix: \n";
	SM.addData(1, 1, 2);
	SM.addData(2, 2, 2);
	SM.addData(4, 2, 3);
	SM.addData(3, 3, 5);
	SM.addData(4, 3, 1);
	SM.printSparseMatrix();

	cout << "\nRemove from the sparse matrix: \n";
	SM.removeData(1, 1);
	SM.printSparseMatrix();

	cout << "\nTransposition of a sparse matrix: \n";
	SM.transposeSparseMatrix();
	SM.printSparseMatrix();

	SparseMatrix SM1;
	cout << "\n(1)Sparse matrix: \n";
	SM1.addData(1, 1, 1);
	SM1.addData(2, 3, 8);
	SM1.addData(3, 4, 5);
	SM1.addData(4, 1, 3);
	SM1.addData(4, 3, 7);
	SM1.printSparseMatrix();

	cout << "\n(1)Sparse matrix(change the value): \n";
	SM1.changeElementInSparceMatrix(1,1,5);
	SM1.changeElementInSparceMatrix(1, 2, 3);
	SM1.printSparseMatrix();





	system("pause");
	return 0;
}

