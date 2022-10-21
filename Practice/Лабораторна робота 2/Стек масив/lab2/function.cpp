#include "function.h"
#include <iostream>
using namespace std;

Stack::Stack()
{
	top = 0;
	size = 10;
	arr = new itemType[size];
}
Stack::~Stack()
{
	delete[] arr;
}
void Stack::push(itemType value)
{
	if (top >= size)
	{
		size = size * 2;
		function();
	}
	arr[top] = value;
	++top;
}
itemType Stack::pop()
{
	itemType result = itemType();
	if (!isEmpty())
	{
		--top;
		result = arr[top];
		if (top <= size / 2)
		{
			size = size * 2;
			function();
		}
	}
	return result;
}
bool Stack::isEmpty()
{
	return (top == 0);
}
size_t Stack::getSize()
{
	return size;
}
size_t Stack::getLegth()
{
	return top;
}

void Stack::print()
{
	for (size_t i = 0; i < top; ++i)
	{
		cout << arr[i] << ' ';
	}
	cout << endl;
}
itemType Stack::peekTop()
{
	return arr[top - 1];
}
bool Stack::checkBail()
{
	Stack stackToCheck;
	int close = 0;
	for (size_t i = 0; i < top; ++i)
	{
		if (arr[i] == '(')
		{
			stackToCheck.push(arr[i]);
			--close;
		}
		else if (arr[i] == ')')
		{
			stackToCheck.pop();
			++close;
		}
	}
	if (close > 0)
	{
		return false;
	}
	return stackToCheck.isEmpty();
}

