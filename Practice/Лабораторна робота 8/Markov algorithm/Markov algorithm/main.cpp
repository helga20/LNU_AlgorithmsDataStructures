#include <Windows.h>
#include<iostream>
#include<vector>
#include<string>
#include "string_realization.h"
using namespace std;

template<typename Value>
struct String_values
{
	Value originally;
	Value after_algorithm;
};

template<typename Value>
void MarkovAldorithm(Value& firstV, vector<String_values<Value>>& SV)
{
	int i = 0;
	while (i < SV.size())
	{
		int isFound = firstV.findIndex(SV[i].originally);
		if (isFound != -1)
		{
			if (SV[i].after_algorithm[SV[i].after_algorithm.strSize() - 1] == '#')
			{
				Value last(SV[i].after_algorithm);
				last.erase(last.strSize() - 1, 1);
				firstV.replace(isFound, SV[i].originally.strSize(), last);
				break;
			}
			firstV.replace(isFound, SV[i].originally.strSize(), SV[i].after_algorithm);
			i = 0;
		}
		else
		{
			i++;
		}
	}
}

int main() 
{
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);

	vector<String_values<String> > strVal;

	/*String_values<String> first_rule;
	first_rule.originally = "чо";
	first_rule.after_algorithm = "";

	String_values<String> second_rule;
	second_rule.originally = "ра";
	second_rule.after_algorithm = "ар";

	String_values<String> third_rule;
	third_rule.originally = "01";
	third_rule.after_algorithm = "10";

	String_values<String> fourth_rule;
	fourth_rule.originally = "тес";
	fourth_rule.after_algorithm = "сет";

	String_values<String> fifth_rule;
	fifth_rule.originally = "ро";
	fifth_rule.after_algorithm = "то";

	String_values<String> sixth_rule;
	sixth_rule.originally = "20";
	sixth_rule.after_algorithm = "1";

	String_values<String> seventh_rule;
	seventh_rule.originally = "ол";
	seventh_rule.after_algorithm = "Оля";

	String_values<String> eighth_rule;
	eighth_rule.originally = "ПМ";
	eighth_rule.after_algorithm = "Прикладна математика";

	String_values<String> ninth_rule;
	ninth_rule.originally = "І";
	ninth_rule.after_algorithm = "інформатика";

	String_values<String> concluding_rule;
	concluding_rule.originally = ".";
	concluding_rule.after_algorithm = "#";

	strVal.push_back(first_rule);
	strVal.push_back(second_rule);
	strVal.push_back(third_rule);
	strVal.push_back(fourth_rule);
	strVal.push_back(fifth_rule);
	strVal.push_back(sixth_rule);
	strVal.push_back(seventh_rule);
	strVal.push_back(eighth_rule);
	strVal.push_back(ninth_rule);
	strVal.push_back(concluding_rule);

	String my("рядочок; шрам; 10; 1011; 01; текст; таро; 20200; ол; ПМ і І.");
	cout << my << "\n\n";*/
	String_values<String> first_rule;
	first_rule.originally = "аб";
	first_rule.after_algorithm = "ба";

	String_values<String> second_rule;
	second_rule.originally = "а";
	second_rule.after_algorithm = "аа";

	strVal.push_back(first_rule);
	strVal.push_back(second_rule);

	String my("аб");
	cout << my << "\n\n";
	MarkovAldorithm<String>(my, strVal);
	cout << my << "\n\n\n";

	system("pause");
	return 0;
}