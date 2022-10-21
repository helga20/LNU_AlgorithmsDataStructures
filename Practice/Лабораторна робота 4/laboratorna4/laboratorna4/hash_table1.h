#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class HashTable
{
private:
	static const int hash = 10;
	list<pair<int, string>>table[hash];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	void printTable();
};

