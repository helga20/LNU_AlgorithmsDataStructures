
#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include<iostream>
#include<cmath>
#include<stack>
using namespace std;

//int priority(char c)
//{
//	switch (c)
//	{
//	case '*': case '/': return 2;
//	case '+': case '-': return 1;
//	case '#': case '(': case ')': return 0;
//	default: return -1;
//	}
//}
//
//bool isDigital(char c)
//{
//	return '0' <= c && c <= '9';
//}
//
//bool isOperand(char c)
//{
//	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
//}
//
//string toPostfix(string infix)
//{
//	string postfix;
//	stack <char> Stack;
//	Stack.push('#');
//	for (char c : infix)
//	{
//		if (isdigit(c))
//			postfix += c;
//		else
//		{
//			int p = priority(c);
//			switch (c)
//			{
//			case '+': case '-': case '*': case '/':
//				while (priority(Stack.top()) >= p)
//				{
//					postfix += Stack.top(); Stack.pop();
//				}
//				Stack.push(c); break;
//			case '(':
//				Stack.push(c); break;
//			case ')':
//				while (Stack.top() != '(')
//				{
//					postfix += Stack.top();
//					Stack.pop();
//				}
//				Stack.pop(); break;
//			}
//		}
//	}
//	while (Stack.top() != '#')
//	{
//		postfix += Stack.top(); Stack.pop();
//	}
//	return postfix;
//}
//
//int calculate(string expr)
//{
//	stack <int> Stack;
//	for (char c : expr)
//	{
//		if (isdigit(c))
//		{
//			Stack.push(c - '0');
//		}
//		else
//		{
//			int right = Stack.top(); Stack.pop();
//			int left = Stack.top(); Stack.pop();
//			switch (c)
//			{
//			case '+': Stack.push(left + right); break;
//			case '-': Stack.push(left - right); break;
//			case '*': Stack.push(left * right); break;
//			case '/': Stack.push(left / right); break;
//			}
//		}
//	}
//	return Stack.top();
//}
//
//int main()
//{
//	string infix = "(((2+3)*2-5)*2+1)*2-7";
//	cout << "Infix notation: " << infix << endl;
//	//string postfix;
//	//postfix = toPostfix(infix);
//	string postfix = "23+2*5-2*1+2*7-";
//	cout << "Postfix notation: " << postfix << endl;
//	cout << "Result: " << calculate(postfix) << endl;
//	cout << "\n";
//
//	system("pause");
//	return 0;
//}



double Num(char ch) {
	double value;
	value = ch;
	return float(value - '0');
}
int isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
		return 1;
	return -1;
}
int isOperand(char ch) {
	if (ch >= '0' && ch <= '9')
		return 1;
	return -1;
}
double operation(double a, double b, char o) {
	if (o == '+')
		return b + a;
	else if (o == '-')
		return b - a;
	else if (o == '*')
		return b * a;
	else if (o == '/')
		return b / a;
	else if (o == '^')
		return pow(b, a);
	else
		return INT_MIN;
}
double Postfix(string postfix) {
	double a, b;
	stack<char> stack;
	string::iterator it;
	for (it = postfix.begin(); it != postfix.end(); it++) {
		if (isOperator(*it) != -1) {
			a = stack.top();
			stack.pop();
			b = stack.top();
			stack.pop();
			stack.push(operation(a, b, *it));
		}
		else if (isOperand(*it) > 0) {
			stack.push(Num(*it));
		}
	}
	return stack.top();
}
int main() {
	//cout<< "(6+5-1)/(3*2)";
	string post = "65+1-32*/";
	cout << post << endl;
	cout << "The result is: " << Postfix(post);
}

