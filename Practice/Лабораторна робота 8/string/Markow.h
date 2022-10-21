#pragma once
#include"String.h"

//arbitary rules for string
string algorithm_markowa_in_standard_type(string str,char*  p1,char* p2,char* p3) 
{
	string rezult,rezult1,rezult2,rezult3,rezult4; /*variables for save rezult*/

	//first rule
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.size(); ++j)
		{
			while (str[j] == p1[i] && str[j + 1] == p1[i + 1]) 
			{
				rezult += str[j];
				str[j] = p1[2];
				break;
			}
		}
	}
	for (int j = 0; j < str.size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			rezult1 += str[j];
			break;
		}
	}

	str = rezult1;
	//second rule
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.size(); ++j) 
		{
			while (str[j] == p2[i] && str[j + 1] == p2[i + 1]) 
			{
				rezult2 += str[j];
				str[j] = p2[2];
				break;
			}
		}
	}
	for (int j = 0; j < str.size(); ++j) 
	{
		while (str[j] != p2[2]) 
		{
			rezult2 += str[j];
			break;
		}
	}
	str = rezult2;
	//check first rule again

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.size(); ++j) 
		{
			while (str[j] == p1[i] && str[j + 1] == p1[i + 1]) 
			{
				rezult += str[j];
				str[j] = p1[2];
				break;
			}
		}
	}
	for (int j = 0; j < str.size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			rezult3 += str[j];
			break;
		}
	}
	
	str = rezult3;
	//third rule

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.size(); ++j) 
		{
			while (str[j] == p3[i] && str[j + 1] == p3[i + 1]) 
			{
				rezult += str[j];
				str[j] = ' ';
				break;
			}
		}
	}
	for (int j = 0; j < str.size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			rezult4 += str[j];
			break;
		}
	}

	str = rezult4;

	return str;
}

//arbitary rules for String
String markow_in_String(String str, char*  p1, char* p2, char* p3) 
{
	String r,r1, r2, r3, r4; /*variables for save rezult*/

	//first rule
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.get_size(); ++j) 
		{
			while (str[j] == p1[i] && str[j + 1] == p1[i + 1]) 
			{
				r += str[j];
				str[j] = ' ';
				break;
			}
		}
	}
	for (int j = 0; j < str.get_size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			r += str[j];
			break;
		}
	}
	str = r1;
	//second rule

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.get_size(); ++j)
		{
			while (str[j] == p2[i] && str[j + 1] == p2[i + 1]) 
			{
				r2 += str[j];
				str[j] = p2[2];
				break;
			}
		}
	}
	for (int j = 0; j < str.get_size(); ++j) 
	{
		while (str[j] != p2[2]) 
		{
			r2 += str[j];
			break;
		}
	}
	str = r2;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.get_size(); ++j) 
		{
			while (str[j] == p1[i] && str[j + 1] == p1[i + 1]) 
			{
				r += str[j];
				str[j] = ' ';
				break;
			}
		}
	}
	for (int j = 0; j < str.get_size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			r3 += str[j];
			break;
		}
	}
	//check first rule again
	str = r3;
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < str.get_size(); ++j)
		{
			while (str[j] == p3[i] && str[j + 1] == p3[i + 1]) 
			{
				r += str[j];
				str[j] = p3[2];
				break;
			}
		}
	}
	//third rule
	for (int j = 0; j < str.get_size(); ++j) 
	{
		while (str[j] != ' ') 
		{
			r4 += str[j];
			break;
		}
	}
	//better output by replace
	str = r4;
	for (int i = 0; i <= str.get_size(); ++i) 
	{
		while (str[i] == ' ') 
		{
			str = str.replace(i, i+1);
			break;
		}
	}

	return str;
}

