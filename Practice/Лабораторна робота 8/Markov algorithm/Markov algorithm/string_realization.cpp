#include "string_realization.h"
#include<iostream>
#include<vector>
#include<string>
using namespace std;

String::String()
{
	size = 1;
	str = new char[size];
	str[size - 1] = '\0';
}

String::String(const char* entered)
{
	size = strlen(entered) + 1;
	str = new char[size];

	for (int i = 0; i < (size - 1); ++i)
	{
		str[i] = entered[i];
	}

	str[size - 1] = '\0';
}

String::String(const String& S)
{
	size = S.size;
	str = new char[size];

	for (int i = 0; i < size - 1; ++i)
	{
		str[i] = S.str[i];
	}

	str[size - 1] = '\0';
}

String::~String()
{
	delete[] str;
}

int String::strSize()const
{
	return strlen(str);
}

void String::erase(unsigned index, unsigned sz)
{
	for (int i = index; i < size - sz; ++i)
	{
		str[i] = str[i + sz];
	}

	size -= sz;
}

int String::findIndex(const String& S)const
{
	int index = -1;
	bool is_index = false;
	for (int i = 0; i < strSize() - S.strSize() + 1; ++i)
	{
		int count = 0;
		if (str[i] == S[count])
		{
			is_index = true;
			++count;
			while (is_index && count < S.strSize())
			{
				if (str[count + i] != S[count])
				{
					is_index = false;
					break;
				}
				++count;
			}
			if (is_index)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

void String::replace(size_t index, size_t sz, const String& S)
{
	if (sz == S.strSize())
	{
		int count = 0;
		for (int i = index; i < sz + index; ++i)
		{
			str[i] = S[count];
			++count;
		}
	}

	else
	{
		int str_size = S.strSize();
		char* temporary = new char[size + str_size - sz];

		for (int i = 0; i < index; ++i)
		{
			temporary[i] = str[i];
		}

		for (int i = index, j = 0; i < index + str_size; ++i, ++j)
		{
			temporary[i] = S[j];
		}

		for (int i = index; i + sz < size; ++i)
		{
			temporary[i + str_size] = str[i + sz];
		}
		 
		size = size + str_size - sz;
		delete[] str;

		str = temporary;
		str[size - 1] = '\0';
	}
}