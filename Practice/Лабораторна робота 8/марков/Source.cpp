#include <iostream>
#include<string>
#include<vector>
#include "Header1.h"
using namespace std;

template<typename ValueClass>
struct Elements
{
	ValueClass before;
	ValueClass after;
};

template<typename ValueClass>
void markovAldorithm(ValueClass& first, vector<Elements<ValueClass>>& v)
{
	unsigned i = 0;
	while (i < v.size())
	{
		int isFind = first.find(v[i].before);
		if (isFind != -1)
		{
			if (v[i].after[v[i].after.length() - 1] == '@')
			{
				ValueClass last(v[i].after);
				last.erase(last.length() - 1, 1);
				first.replace(isFind, v[i].before.length(), last);
				break;
			}
			first.replace(isFind, v[i].before.length(), v[i].after);
			i = 0;
	
		}
		else
		{
			++i;
		}	
		/*cout << vP[i].before << " ";
		cout << "\n";
		 cout << vP[i].after << " ";*/
	}	
}
int main(){
	
		vector<Elements<MyString> > vE;
		
		Elements<MyString> one;
		one.before = "london";
		one.after = "London";
		Elements<MyString> two;
		two.before = "I";
		two.after = "is";
		Elements<MyString> three;
		three.before = "T";
		three.after = "the";
		Elements<MyString> four;
		four.before = "C";
		four.after = "capital";
		Elements<MyString> five;
		five.before = "GB";
		five.after = "Great Britain";
		Elements<MyString> six;
		six.before = ".";
		six.after = "@";

		vE.push_back(one);
		vE.push_back(two);
		vE.push_back(three);
		vE.push_back(four);
		vE.push_back(five);
		vE.push_back(six);

		MyString my("T london I T C of GB.");
		cout << my<<"\n\n";
		markovAldorithm<MyString>(my, vE);
		cout <<my<<"\n\n\n";
	
}