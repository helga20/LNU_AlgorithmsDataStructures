#include <iostream>
#include <stack>
#include"table.h"
using namespace std;

Table::Table(int startSize)
	: size(startSize), count(0), place(0)
{
	keys = new KeyNode[size];
	values = new ValueNode[size];
}

Table::~Table()
{
	delete[] keys;
	delete[] values;
}

void Table::resize()
{
	int newSize = size + 100;
	KeyNode* newKeys = new KeyNode[newSize];
	ValueNode* newValues = new ValueNode[newSize];
	for (int i = 0; i < size; i++)
	{
		newKeys[i] = keys[i];
		newValues[i] = values[i];
	}
	delete[] keys; keys = newKeys;
	delete[] values; values = newValues;
	size = newSize;
}

void Table::press()
{
	while (values[place - 1].index == -1)
		--place;
	for (int i = 0; i < place; i++)
	{
		if (values[i].index == -1)
		{
			values[i] = values[--place];
			keys[values[i].index].index = i;
		}
	}
}

bool Table::find(int key, int& index)
{
	int a = 0; int b = count - 1;
	while (a <= b)
	{
		int c = (a + b) / 2;
		if (key == keys[c].key)
		{
			index = c;
			return true;
		}
		if (key < keys[c].key)
		{
			b = c - 1;
		}
		else
		{
			a = c + 1;
		}
	}
	index = a;
	return false;
}

void Table::store(int key, const string& value, int i)
{
	if (count == size) resize();
	if (place == size) press();
	for (int j = count; j > i; --j)
	{
		keys[j] = keys[j - 1];
		values[keys[j].index].index = j;
	}
	keys[i].key = key; keys[i].index = place;
	values[place].value = value; values[place].index = i;
	++count;
	++place;
}

int Table::getCount()
{
	return count;
}

Table& Table::put(int key, const string& value)
{
	int i;
	if (find(key, i))
	{
		values[keys[i].index].value = value;
	}
	else
	{
		store(key, value, i);
	}
	return *this;
}

Table& Table::erase(int key)
{
	int i;
	if (find(key, i))
	{
		values[keys[i].index].index = -1;
		for (int j = i; j < count - 1; j++)
		{
			keys[j] = keys[j + 1];
			values[keys[j].index].index = j;
		}
		--count;
	}
	return *this;
}

bool Table::contain(int key)
{
	for (int i = 0; i < place; ++i)
	{
		if (keys[i].index != -1 && keys[i].key == key)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	return -1;
}

string& Table::getValue(int key)
{
	for (int i = 0; i < place; ++i)
	{
		if (keys[i].index != -1 && keys[i].key == key)
		{
			return values[keys[i].index].value;
		}
		//return;
	}
}

int Table::getKey(const string& value)
{
	for (int i = 0; i < place; ++i)
	{
		if (values[i].index != -1 && values[i].value == value)
		{
			return keys[values[i].index].key;
		}
	}
	return-1;
}

string& Table::operator[](int key)
{
	int i;
	if (!find(key, i))
	{
		store(key, string(), i);
	}
	return values[keys[i].index].value;
}

void Table::print()
{
	if (count == 0)
	{
		cout << "Table is empty" << endl;
	}
	else
		for (int i = 0; i < count; ++i)
		{
			cout << keys[i].key << " --> " << values[keys[i].index].value << endl;
		}
}

int Table::getKeys()
{
	int* ks = new int[count];
	for (int i = 0; i < count; ++i)
	{
		return ks[i] = keys[i].key;
	}
}

string& Table::getValues()
{
	string* vs = new string[count];
	for (int i = 0, j = 0; i < place; ++i)
	{
		if (values[i].index != -1)
		{
			vs[j++] = values[i].value;
		}
		return vs[i];
	}
}

void Table::keysDo(void (*KeyDelegate) (int))
{
	for (int i = 0; i < count; ++i)
	{
		KeyDelegate(keys[i].key);
	}
}

void Table::valuesDo(void (*ValueDelegate) (string&))
{
	for (int i = 0; i < count; ++i)
	{
		ValueDelegate(values[i].value);
	}
}

void Table::Do(void (*PairDelegate) (int, string&))
{
	for (int i = 0; i < count; ++i)
	{
		PairDelegate(keys[i].key, values[keys[i].index].value);
	}
}

void printPair(int key, string& value)
{
	cout << value << "'s code is " << key << endl;
}

