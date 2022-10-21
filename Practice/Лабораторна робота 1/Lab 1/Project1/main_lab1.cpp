#include <iostream>
#include "lab1.h"

using namespace std;

int main()
{
	int n, i; 
	cout << "How many elements in the array? ";
	cin >> n;
	int* arr = new int[n]; 
	cout << "\nEnter array of " << n << " elements: \n";
	creatArray(arr, n);

    BinaryInsertionSort(arr, n);
    cout << "\nAfter sorting (in ascending order): ";

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n";

	cout << "\nAfter sorting (in descending order): ";

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	delete[] arr;

	cout << "\n\n";
	system("pause");
	return 0;
}



