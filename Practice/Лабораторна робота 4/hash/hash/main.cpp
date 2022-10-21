#include <iostream>
#include <string>
#include "hash_table.h"

using namespace std;

int main()
{
	cout << "\nHash Table\n";
	HashTable<string> HT1;

	HT1.Add("Kyiv");
	HT1.Add("Lviv");
	HT1.Add("Odesa");
	HT1.Add("Kherson");
	HT1.Add("Dnipro");
	HT1.Print();

	HT1.Remove("Dnipro");
	HT1.Remove("Yavoriv");
	HT1.Remove("Odesa");
	HT1.Print();

	return 0;
}
