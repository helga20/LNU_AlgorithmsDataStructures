#pragma once
using namespace std;

class HashTable
{
private:
    list<int>* table;
    int total_elements;

    int getHash(int key)
    {
        return key % total_elements;
    }

public:
    HashTable(int n);
    ~HashTable();
    void insertElement(int key);
    void removeElement(int key);
    void printAll();
};
