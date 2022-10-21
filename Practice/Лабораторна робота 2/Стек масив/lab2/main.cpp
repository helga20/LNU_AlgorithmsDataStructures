#include <iostream> 
#include "function.h"
#include <stack>
using namespace std;

int main()
{
	Stack yourStack;
	size_t nSymbol;
	cout << "How many symbols to enter?\n";
	cin >> nSymbol;
	cout << endl;

	cout << "\nPlease, input symbols: " << endl;
	itemType n;
	for (size_t i = 0; i < nSymbol; i++)
	{
		cin >> n;
		yourStack.push(n);
	}
	cout << "\nYour stack: ";
	yourStack.print();

	for (size_t i = 0; i < nSymbol / 2; i++)
	{
		yourStack.pop();
	}

	cout << "\Top element: ";
	cout << yourStack.peekTop();
	cout << endl;

	cout << "\Max size of array: ";
	cout << yourStack.getSize();
	cout << endl;

	cout << "\Size of array: ";
	cout << yourStack.getLegth();
	cout << endl;
	cout << "\n";

	if (yourStack.checkBail())
	{
		cout << "Everything is good with bails\n";
	}
	else
	{
		cout << "Error! Problems with bails\n";
	}

	system("pause");
	return 0;
}





