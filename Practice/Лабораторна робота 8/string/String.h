#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class String {
private:
	int size;
	char* str;
public:
	String() 
	{
		size = 20;
		str = new char[size];
	}
	String(char * n) 
	{
		str = n;
		size = strlen(str);
	}
	//check if the str is empty
	bool is_empty() 
	{
		return str[0] == ' ';
	}
	//resize function
	void resize(int n) 
	{
		char* bigger_str = new char[size + n];
		for (int i = 0; i < size; ++i) 
		{
			bigger_str[i] = str[i];
		}
		size = size + n;
		delete[] str;
		str = bigger_str;
	}
	//replace two elements in array
	String replace(int index1, int index2) 
	{
		swap(str[index1], str[index2]);
		return str;
	}
	//get  array  of char
	char * get_str() 
	{
		return str;
	}
	//get the size of array
	int get_size() 
	{
		return size - 1;
	}
	
	friend ostream& operator<<(ostream& os, String& n);/*operator of output*/
	//friend istream& operator>>(ostream& is, String& n); /*operator of input*/
	char& operator[](int i) 
	{
		if (i >= this->size) 
		{
			cerr << "Error in String limits: " << i << " bad index\n";
			exit(1);
		}
		return str[i];
	}
	//overload the operator []
	const char& operator[](int i)const 
	{
		if (i >= this->size) 
		{
			cerr << "Error in String limits: " << i << " bad index\n";
			exit(1);
		}
		return str[i];
	}
	//overload the operator=
	String operator=(String s) 
	{
		String m;
		for (int i = 0; i < s.get_size(); ++i) 
		{
			m[i] = s[i];
		}
		return m;
	}
	//operator + for concatination of Strings
	String operator+(String& s1) 
	{
		String rezult;
		int this_len = strlen(this->str);
		int othe_len = strlen(s1.get_str());
		int r = this_len + othe_len + 1;
		rezult.resize(this_len + othe_len + 1);
		int i = 0;
		for (; i < this_len; ++i) 
		{
			rezult.get_str()[i] = this->str[i];
		}
		for (int j = 0; j < othe_len; ++i,++j) 
		{
			rezult.get_str()[i] = s1.get_str()[j];
		}
		rezult.get_str()[this_len + othe_len] = '\0';
		return rezult;
	}
	String operator+=(char a) 
	{
		String rezult;
		rezult.resize(size + 1);
		rezult[size] = a;
		return rezult;
	}
};

ostream& operator<<(ostream& os, String& n) 
{
	os << n.get_str() << endl;
	return os;
}

