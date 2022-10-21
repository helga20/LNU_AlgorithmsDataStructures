#include <iostream>
#include <stack>
#include "table.h"

using namespace std;

int main()
{
	cout << "-------------" << endl;
	Table T(3);
	T.print();
	cout << "Table is created. Number of entries: " << T.getCount() << endl;
	T.put(960309027, "Smart+");
	T.put(680571414, "Entertainment without limits").put(674266248, "Communication without borders");
	T.print();
	cout << "---Number of entries: " << T.getCount() << endl;
	T.erase(680571414).print();
	cout << "---Number of entries: " << T.getCount() << endl;
	T.put(680571414, "Entertainment without limits").put(672731730, "Video without limits").print();
	cout << "---Table is resized. Number of entries: " << T.getCount() << endl;
	cout << "-------------" << endl;
	cout << "Does the table contain the key [3806754322580]? " << T.contain(6754322580) << endl;
	cout << "Does the table contain the key [380672731730]? " << T.contain(672731730) << endl;
	cout << "The value at key [380960309027] is " << T.getValue(960309027) << endl;
	cout << "The key for value [Smart+] is " << T.getKey("Smart+") << endl;
	cout << "-------------" << endl;
	cout << "Adding the pair 1-->Heat+ by tariff []:" << endl;
	T[1] = "Heat+"; T.print();
	cout << "Getting the value by tariff []: " << T[960309027] << endl;
	cout << "-------------" << endl;
	int Keys = T.getKeys();
	cout << "KEYS: ";
	for (int i = 0; i < T.getCount(); ++i)
	{
		cout << T.getValues()[i] << ' ';
	}
	cout << endl;
	string Values = T.getValues();
	cout << "VALUES: ";
	for (int i = 0; i < T.getCount(); ++i)
	{
		cout << Values[i] << ' ';
	}
	cout << endl << "---Sending pairs to function---" << endl;
	T.Do(printPair);

	return 0;
}