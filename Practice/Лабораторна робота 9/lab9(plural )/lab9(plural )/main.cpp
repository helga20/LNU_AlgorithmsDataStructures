#include "set.h"
#include <set>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	Set s;

	int flag = 0;
	int fSetSize = 4;
	int sSetSize = 7;
	char fSet[4] = { 'O','L','I','A' };
	char sSet[7]{ 'K','R','A','V', 'E', 'T', 'S' };

	cout << "First set: ";
	for (int i = 0; i < fSetSize; ++i)
	{
		cout << fSet[i];
	}

	cout << "\nSecond set: ";
	for (int i = 0; i < sSetSize; ++i)
	{
		cout << sSet[i];
	}
	cout << '\n';

	cout << "\nRemove 'O' from the set: ";
	s.setRemove('O');

	cout << "\nUnion: ";
	s.setUnion(fSet, fSetSize, sSet, sSetSize);

	cout << "\nIntersection: ";
	s.setIntersection(fSet, fSetSize, sSet, sSetSize);

	cout << "\nDifference (f-s): ";
	s.setDifference(fSet, fSetSize, sSet, sSetSize);

	cout << "\nDifference (s-f): ";
	s.setDifference(sSet, sSetSize, fSet, fSetSize);

	cout << '\n';
	system("pause");
	return 0;
}




