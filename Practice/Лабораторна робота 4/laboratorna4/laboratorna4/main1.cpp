#include <iostream>
#include <string>
#include <list>
#include "hash_table1.h"

using namespace std;

int main()
{
	HashTable HT;
	if (HT.isEmpty())
	{
		cout << "Correct answer." << endl;
	}
	else
	{
		cout << "Please, check your code." << endl;
	}
	HT.insertItem(500, "Kyiv");
	HT.insertItem(600, "Lniv"); 
	HT.insertItem(750, "Odesa");
	HT.insertItem(300, "Kharkiv");
	HT.insertItem(250, "Kherson");
	HT.insertItem(100, "Yavoriv");
	HT.insertItem(50, "Vinnytsia");
	HT.insertItem(50, "Ternopil");

	HT.printTable();

	HT.removeItem(750);
	HT.removeItem(60);

	if (HT.isEmpty())
	{
		cout << "Please, check your code.";
	}
	else
	{
		cout << "Correct answer." << endl;
	}


	return 0;
}


