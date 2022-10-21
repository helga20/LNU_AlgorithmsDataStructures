#include "set.h"
#include <iostream>
#include <set>
using namespace std;

void Set::setDisplay(char* resultSet, int resultSetSize)
{
	for (int i = 0; i < resultSetSize; ++i)
	{
		cout << resultSet[i] << " ";
	}
	cout << "\n";
}

void Set::setUnion(char* fSet, int fSetSize, char* sSet, int sSetSize)
{
	char resultSet[20];
	int flag, resultSetSize = 0;

	for (int i = 0; i < fSetSize; ++i)
	{
		resultSet[i] = fSet[i];
		resultSetSize++;
	}

	for (int i = 0; i < sSetSize; ++i)
	{
		flag = 0;
		for (int j = 0; j < resultSetSize; ++j)
		{
			if (sSet[i] == resultSet[j])
			{
				flag = 1; break;
			}
		} // якщо елемент з sSet збігається з елементом fSet
		if (flag == 0)
		{
			resultSet[resultSetSize] = sSet[i];
			resultSetSize++;
		}
	}
	setDisplay(resultSet, resultSetSize);
}

void Set::setIntersection(char* fSet, int fSetSize, char* sSet, int sSetSize)
{
	char resultSet[20];
	int flag = 0, resultSetSize = 0;

	for (int i = 0; i < sSetSize; ++i)
	{
		for (int j = 0; j < fSetSize; ++j)
		{
			if (sSet[i] == fSet[j])
			{
				resultSet[resultSetSize] = sSet[i];
				resultSetSize++; break;
			}
		}
	}
	setDisplay(resultSet, resultSetSize);
}

void Set::setDifference(char* fSet, int fSetSize, char* sSet, int sSetSize)
{
	char resultSet[20];
	int flag = 0, resultSetSize = 0;

	for (int i = 0; i < fSetSize; ++i)
	{
		flag = 0;
		for (int j = 0; j < sSetSize; ++j)
		{
			if (fSet[i] == sSet[j])
			{
				flag = 1; break;
			}
		} // якщо елемент з sSet збігається з елементом fSet
		if (flag == 0)
		{
			resultSet[resultSetSize] = fSet[i];
			resultSetSize++;
		}
	}
	setDisplay(resultSet, resultSetSize);
}

void Set::setRemove(char del)
{
	int fSetSize = 4;
	char fSet[4] = { 'O','L','I','A' };
	for (int i = 0; i < fSetSize; ++i)
	{
		if (fSet[i] == del)
		{
			fSet[i] = fSet[i] - del;
		}
		cout << fSet[i];
	}
	cout << "\n";
}
