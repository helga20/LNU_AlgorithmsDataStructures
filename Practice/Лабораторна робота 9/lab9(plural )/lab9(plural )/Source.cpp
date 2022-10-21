
//class Set
//{
//public:
//
//	void setDisplay(int* resultSet, int resultSetSize);
//	void setUnion(int* fSet, int fSetSize, int* sSet, int sSetSize);
//	void setIntersection(int* fSet, int fSetSize, int* sSet, int sSetSize);
//	void setDifference(int* fSet, int fSetSize, int* sSet, int sSetySize);
//};
//
//void Set::setDisplay(int* resultSet, int resultSetSize)
//{
//	for (int i = 0; i < resultSetSize; ++i)
//	{
//		cout << resultSet[i] << " ";
//	}
//	cout << "\n";
//}
//
//void Set::setUnion(int* fSet, int fSetSize, int* sSet, int sSetSize)
//{
//	int resultSet[20];
//	int flag = 0, resultSetSize = 0;
//
//	for (int i = 0; i < fSetSize; ++i)
//	{
//		resultSet[i] = fSet[i];
//		resultSetSize++;
//	}
//
//	for (int i = 0; i < sSetSize; ++i)
//	{
//		flag = 0;
//		for (int j = 0; j < resultSetSize; ++j)
//		{
//			if (sSet[i] == resultSet[j])
//			{
//				flag = 1; break;
//			}
//		}
//		if (flag == 0)
//		{
//			resultSet[resultSetSize] = sSet[i];
//			resultSetSize++;
//		}
//	}
//	setDisplay(resultSet, resultSetSize);
//}
//
//void Set::setIntersection(int* fSet, int fSetSize, int* sSet, int sSetSize)
//{
//	int resultSet[20];
//	int flag = 0, resultSetSize = 0;
//
//	for (int i = 0; i < sSetSize; ++i)
//	{
//		for (int j = 0; j < fSetSize; ++j)
//		{
//			if (sSet[i] == fSet[j])
//			{
//				resultSet[resultSetSize] = sSet[i];
//				resultSetSize++; break;
//			}
//		}
//	}
//	setDisplay(resultSet, resultSetSize);
//}
//
//void Set::setDifference(int* fSet, int fSetSize, int* sSet, int sSetSize)
//{
//	int resultSet[20];
//	int flag = 0, resultSetSize = 0;
//
//	for (int i = 0; i < fSetSize; ++i)
//	{
//		flag = 0;
//		for (int j = 0; j < sSetSize; ++j)
//		{
//			if (fSet[i] == sSet[j])
//			{
//				flag = 1; break;
//			}
//		}
//		if (flag == 0)
//		{
//			resultSet[resultSetSize] = fSet[i];
//			resultSetSize++;
//		}
//	}
//	setDisplay(resultSet, resultSetSize);
//}

//#include "set.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int fSet[10]; int sSet[10];
//	int fSetSize; int sSetSize;
//	int flag = 0;
//
//	cout << "Enter n of elements to be in 1 set:\n";
//	cin >> fSetSize;
//	cout << "Enter " << fSetSize << "elemets of 1 set:\n";
//	for (int i = 0; i < fSetSize; ++i)
//	{
//		cin >> fSet[i];
//	}
//
//	cout << "Enter n of elements to be in 2 set:\n";
//	cin >> sSetSize;
//	cout << "Enter " << sSetSize << "elemets of 1 set:\n";
//	for (int i = 0; i < sSetSize; ++i)
//	{
//		cin >> sSet[i];
//	}
//
//	Set s;
//
//	cout << "Union: ";
//	s.setUnion(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Intersection: ";
//	s.setIntersection(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Difference (f-s): ";
//	s.setDifference(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Difference (s-f): ";
//	s.setDifference(sSet, sSetSize, fSet, fSetSize);
//
//	system("pause");
//	return 0;
//}


//#include "set.h"
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	char fSet[10]; char sSet[10];
//	int fSetSize; int sSetSize;
//	int flag = 0;
//
//	cout << "Enter n of elements to be in 1 set:\n";
//	cin >> fSetSize;
//	cout << "Enter " << fSetSize << "elemets of 1 set:\n";
//	for (int i = 0; i < fSetSize; ++i)
//	{
//		cin >> fSet[i];
//	}
//
//	cout << "Enter n of elements to be in 2 set:\n";
//	cin >> sSetSize;
//	cout << "Enter " << sSetSize << "elemets of 1 set:\n";
//	for (int i = 0; i < sSetSize; ++i)
//	{
//		cin >> sSet[i];
//	}
//
//	Set s;
//
//	cout << "Union: ";
//	s.setUnion(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Intersection: ";
//	s.setIntersection(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Difference (f-s): ";
//	s.setDifference(fSet, fSetSize, sSet, sSetSize);
//
//	cout << "Difference (s-f): ";
//	s.setDifference(sSet, sSetSize, fSet, fSetSize);
//
//	system("pause");
//	return 0;
//}
//