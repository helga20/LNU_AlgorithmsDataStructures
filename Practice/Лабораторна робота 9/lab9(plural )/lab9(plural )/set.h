#pragma once
#include <set>
#include <iostream>
using namespace std;

class Set
{

public:

	void setDisplay(char* resultSet, int resultSetSize);
	void setUnion(char* fSet, int fSetSize, char* sSet, int sSetSize);
	void setIntersection(char* fSet, int fSetSize, char* sSet, int sSetSize);
	void setDifference(char* fSet, int fSetSize, char* sSet, int sSetySize);
	void setRemove(char del);
};
