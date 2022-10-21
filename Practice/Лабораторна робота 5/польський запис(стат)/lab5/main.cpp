#include "polish_record.h"
#include <iostream>
#include <stack>
#include <sstream>
using namespace std;

int main()
{
	string dest;
	string source = "(8+9-3)/(1+3*2)+5";
	cout << "Infix notation: " << source << endl;
	if (source.empty()) return 0;
	dest = toPostfix(source);
	cout << "Postfix notation: " << dest << '\n';
	cout << "Result: " << calculate(dest) << "\n\n";
	
	system("pause");
	return 0;
}

