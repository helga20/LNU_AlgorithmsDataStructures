#include <iostream>
#include <list>
#include "function.h"

using namespace std;

int main() 
{
    HashTable ht(3);

    int arr[] = { 2, 4, 6, 8, 10 };

    for (int i = 0; i < 5; i++)
        ht.insertElement(arr[i]);

    cout << "Hash Table" << endl;
    ht.printAll();

    ht.removeElement(4);
    cout << endl << "After deleting 4" << endl;
    ht.printAll();

    return 0;
}