#include <iostream>
#include <list>
#include "function.h"
using namespace std;

HashTable::HashTable(int n)
{
    total_elements = n;
    table = new list<int>[total_elements];
}
HashTable::~HashTable()
{}

void HashTable::insertElement(int key)
{
    table[getHash(key)].push_back(key);
}

void HashTable::removeElement(int key)
{
    int x = getHash(key);

    list<int>::iterator i;
    for (i = table[x].begin(); i != table[x].end(); i++)
    {
        if (*i == key)
            break;
    }

    if (i != table[x].end())
        table[x].erase(i);
}

void HashTable::printAll() 
{
    for (int i = 0; i < total_elements; i++)
    {
        cout << "Index " << i << ": ";
        for (int j : table[i])
            cout << j << " => ";

        cout << endl;
    }
}