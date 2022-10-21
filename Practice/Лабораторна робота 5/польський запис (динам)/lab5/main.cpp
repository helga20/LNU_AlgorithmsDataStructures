#include "polish_record.h"
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	string source, dest;
	cout << "Enter infix notation: \n";
	getline(cin, source);
	if (source.empty()) return 0;
	dest = toPostfix(source);
	cout << "Postfix notation: " << dest << '\n';
	cout << "Result: " << calculate(dest) << "\n\n";
	

	system("pause");
	return 0;
}

