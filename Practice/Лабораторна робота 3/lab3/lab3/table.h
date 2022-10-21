#pragma once
#include <string>
#include <iostream>
using namespace std;

class Table 
{
public:

	struct KeyNode
	{
		unsigned int key;
		int index;
	};
	struct ValueNode
	{
		string value;
		int index;
	};

private:
	int size; 
	int count; 
	int place; 
	KeyNode* keys;
	ValueNode* values;
	void resize(); 
	void press();
	bool find(int key, int& i);
	void store(int key, const string& value, int i);
public:
	Table(int startSize); 
	~Table(); 
	int getCount();
	Table& put(int key, const string& value);
	Table& erase(int key);
	bool contain(int key);
	string& getValue(int key);
	int getKey(const string& value);
	string& operator[](int key);
	void print(); 
	int getKeys();
	string& getValues();
	void keysDo(void (*KeyDelegate) (int));
	void valuesDo(void (*ValueDelegate) (string&));
	void Do(void (*PairDelegate) (int, string&));
};
void printPair(int key, string& value);
