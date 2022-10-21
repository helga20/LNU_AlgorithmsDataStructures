#include <iostream>
#include <stack>
using namespace std;

void printOn(stack<char> s)
{
	char n = s.size();
	for (int i = 0; i < n; i++)
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\n";
}

int main()
{
	stack<char> s;
	s.push('(');
	s.push(')');
	s.push('(');
	s.push(')');
	s.push('(');

	cout << "Stack: ";
	printOn(s);
	cout << "Top: " << s.top() << "\n";

	s.pop();

	cout << "Stack after pop: ";
	printOn(s);

	cout << "Top after pop: " << s.top() << "\n";

	cout << "Stack is empty (1-yes | 0 - no): " << s.empty() << "\n";

	cout << "Size of stack now: " << s.size() << "\n";

	return 0;
}


