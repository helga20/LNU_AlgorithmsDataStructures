#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class MyString
{
	char* nstring;
	unsigned nlength;

public:
	MyString()
	{
		nlength = 1;
		nstring = new char[nlength];
		nstring[nlength - 1] = '\0';
	}

	MyString(const char* input)
	{
		nlength = strlen(input) + 1;
		nstring = new char[nlength];
		for (int i = 0; i < (nlength - 1); ++i)
		{
			nstring[i] = input[i];
		}
		nstring[(nlength - 1)] = '\0';
	}
	
	MyString(const MyString& s)
	{
		nlength = s.nlength;
		nstring = new char[nlength];
		for (int i = 0; i < (nlength - 1); ++i)
		{
			nstring[i] = s.nstring[i];
		}
			nstring[nlength - 1] = '\0';
	}
	~MyString()
	{
		delete[] nstring;
	}

	unsigned length()const
	{
		return strlen(nstring);
	}
	
	const char& operator[](size_t i)const
	{
		return nstring[i];
	}
	char& operator[](size_t i)
	{
		return nstring[i];
	}

	MyString& operator =(const MyString& s)
	{
		nlength = s.nlength;
		delete[] nstring;
		nstring = new char[nlength];
		for (int i = 0; i < nlength - 1; ++i)
		{
			nstring[i] = s.nstring[i];
		}
		nstring[nlength - 1] = '\0';
		return *this;
	}

	void erase(unsigned index, unsigned length)
	{
		for (int i = index; i < nlength - length; ++i)
		{
			nstring[i] = nstring[i + length];
		}
		nlength -= length;
	}
	
	unsigned find(const MyString& s)const
	{
		unsigned index = -1;
		bool isIn = false;
		for (int i = 0; i < length() - s.length() + 1; ++i)
		{
			unsigned count = 0;
			if (nstring[i] == s[count])
			{
				isIn = true;
				++count;
				while (isIn && count < s.length())
				{
					if (nstring[count + i] != s[count])
					{
						isIn = false;
						break;
					}
					++count;
				}
				if (isIn)
				{
					index = i;
					break;
				}
			}
		}
		return index;
	}

	void replace(size_t index, size_t length, const MyString& s)
	{
		if (length == s.length())
		{
			unsigned count = 0;
			for (int i = index; i < length + index; ++i)
			{
				nstring[i] = s[count];
				++count;
			}
		}
		else
		{
			unsigned size = s.length();
			char* temp = new char[nlength + size - length];
			for (int i = 0; i < index; ++i)
			{
				temp[i] = nstring[i];
			}
			for (int i = index, j = 0; i < index + size; ++i, ++j)
			{
				temp[i] = s[j];
			}
			for (int i = index; i + length < nlength; ++i)
			{
				temp[i + size] = nstring[i + length];
			}
			nlength = nlength + size - length;
			delete[] nstring;
			nstring = temp;
			nstring[nlength - 1] = '\0';
		}

	}

	friend ostream& operator <<(ostream& os, const MyString& s)
	{
		os << s.nstring;
		return os;
	}
};