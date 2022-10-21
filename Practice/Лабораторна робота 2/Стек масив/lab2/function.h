#pragma once
#include <string>
#include <iostream>
typedef char itemType;
class Stack
{
private:

	size_t size;
	size_t top;
	itemType* arr;
	void function()
	{
		itemType* itemArr = new itemType[size];
		for (size_t i = 0; i < top; ++i)
		{
			itemArr[i] = arr[i];
		}
		delete[] arr;
		arr = itemArr;
	}

public:

	Stack();
	~Stack();

	void push(itemType value);
	itemType pop();
	bool isEmpty();
	itemType peekTop();
	size_t getSize();
	size_t getLegth();
	bool checkBail();
	void print();
};
