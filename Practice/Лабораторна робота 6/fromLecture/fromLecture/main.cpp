#include <iostream>
#include "sparseMatrix.h"
using namespace std;

int main()
{
    SparseMatrix matr;
    cout << "(1, 1) expected: 0 actual: ";
    cout << matr.get_element(1, 1) << endl;
    cout << "(3, 4) expected: 0 actual: ";
    cout << matr.get_element(3, 4) << endl;

    matr.add_element(1, 1, 11);
    matr.add_element(3, 4, 34);
    cout << "(1, 1) expected: 11 actual: ";
    cout << matr.get_element(1, 1) << endl;
    cout << "(3, 4) expected: 34 actual: ";
    cout << matr.get_element(3, 4) << endl;

    matr.remove_element(3, 4);

    cout << "(3, 4) expected: 0 actual: ";
    cout << matr.get_element(3, 4) << endl;



    return 0;
}

