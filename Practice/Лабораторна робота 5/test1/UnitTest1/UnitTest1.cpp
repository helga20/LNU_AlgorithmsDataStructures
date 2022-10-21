﻿#include "pch.h"
#include "CppUnitTest.h"

#include <string>
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

int priority(char c)
{
	switch (c)
	{
	case '*': case '/': return 2;
	case '+': case '-': return 1;
	case '#': case '(': case ')': return 0;
	default: return -1;
	}
}

bool isDigital(char c)
{
	return '0' <= c && c <= '9';
}

bool isOperand(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

string toPostfix(string infix)
{
	string postfix;
	stack <char> Stack;
	Stack.push('#');
	for (char c : infix)
	{
		if (isdigit(c))
			postfix += c;
		else
		{
			int p = priority(c);
			switch (c)
			{
			case '+': case '-': case '*': case '/':
				while (priority(Stack.top()) >= p)
				{
					postfix += Stack.top(); Stack.pop();
				}
				Stack.push(c); break;
			case '(':
				Stack.push(c); break;
			case ')':
				while (Stack.top() != '(')
				{
					postfix += Stack.top();
					Stack.pop();
				}
				Stack.pop(); break;
			}
		}
	}
	while (Stack.top() != '#')
	{
		postfix += Stack.top(); Stack.pop();
	}
	return postfix;
}

int calculate(string expr)
{
	stack <int> Stack;
	for (char c : expr)
	{
		if (isdigit(c))
		{
			Stack.push(c - '0');
		}
		else
		{
			int right = Stack.top(); Stack.pop();
			int left = Stack.top(); Stack.pop();
			switch (c)
			{
			case '+': Stack.push(left + right); break;
			case '-': Stack.push(left - right); break;
			case '*': Stack.push(left * right); break;
			case '/': Stack.push(left / right); break;
			}
		}
	}
	return Stack.top();
}

int main()
{
	string infix = "(((2+3)*2-5)*2+1)*2-7";
	cout << "Infix notation: " << infix << endl;
	string postfix;
	postfix = toPostfix(infix);
	//string postfix = "23+2*5-2*1+2*7-";
	cout << "Postfix notation: " << postfix << endl;
	cout << "Result: " << calculate(postfix) << endl;
	cout << "\n";

	system("pause");
	return 0;
}


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:	
		TEST_METHOD(Calculation)
		{
			string postfix = "12+";
			Assert::AreEqual(3, calculate(postfix));
		}
		TEST_METHOD(CalculationError)
		{
			string postfix = "32*2-";
			Assert::AreEqual(1, calculate(postfix));
		}
	};
}
