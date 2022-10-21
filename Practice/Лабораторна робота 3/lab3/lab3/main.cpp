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
	T.put(5506, "Vegetables");
	T.put(65971, "Fruits").put(65952, "Apples");
	T.print();
	cout << "---Number of entries: " << T.getCount() << endl;
	T.erase(65971).print();
	cout << "---Number of entries: " << T.getCount() << endl;
	T.put(65971, "Fruits").put(63214, "Bananas").print();
	cout << "---Table is resized. Number of entries: " << T.getCount() << endl;
	cout << "-------------" << endl;
	cout << "Does the table contain the key [65971]? " << T.contain(65971) << endl;
	cout << "Does the table contain the key [65244]? " << T.contain(65244) << endl;
	
	return 0;
}