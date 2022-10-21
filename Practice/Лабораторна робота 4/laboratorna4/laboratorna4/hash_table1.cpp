#include <iostream>
#include <list>
#include <string>
#include "hash_table1.h"

using namespace std;

bool HashTable::isEmpty() const
{
	int sum = 0;
	for (int i=0; i < hash; ++i)
	{
		sum += table[i].size();
	}
	if (!sum)
	{
		return true;
	}
	return false;
}

int HashTable::hashFunction(int key)
{
	return key % hash;
}

void HashTable::insertItem(int key, string value)
{
	int hachValue = hashFunction(key);
	auto& cell = table[hachValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr -> first == key)
		{
			keyExists = true;
			bItr->second = value;
			cout << "Error. Key exists. Value replaced. " << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cell.emplace_back(key, value);
	}
	return;
}

void HashTable::removeItem(int key)
{
	int hachValue = hashFunction(key);
	auto& cell = table[hachValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++)
	{
		if (bItr->first == key)
		{
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Pair removed." << endl;
			break;
		}
	}
	if (!keyExists)
	{
		cout << "Error. Key not found. Pair not removed." << endl;
	}
}

void HashTable::printTable()
{
	for (int i=0; i < hash; ++i)
	{
		if (table[i].size() == 0) continue;
		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++)
		{
			cout << " Key: " << bItr->first << " Value: " << bItr->second << endl;
		}

	}
	return;
}






