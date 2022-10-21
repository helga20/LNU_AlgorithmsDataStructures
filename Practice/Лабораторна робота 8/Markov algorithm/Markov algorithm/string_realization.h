#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class String
{
	char* str;
	int size;

public:
	String();
	String(const char* entered);
	String(const String& S);
	~String();

	int strSize()const;

	const char& operator[](size_t i)const
	{
		return str[i];
	}
	char& operator[](size_t i)
	{
		return str[i];
	}

	String& operator =(const String& S)
	{
		size = S.size;
		delete[] str;

		str = new char[size];
		for (int i = 0; i < (size - 1); ++i)
		{
			str[i] = S.str[i];
		}
		str[size - 1] = '\0';
		return *this;
	}

	void erase(unsigned index, unsigned sz);
	int findIndex(const String& S)const;
	void replace(size_t index, size_t sz, const String& S);

	friend ostream& operator <<(ostream& os, const String& S)
	{
		os << S.str;
		return os;
	}
};