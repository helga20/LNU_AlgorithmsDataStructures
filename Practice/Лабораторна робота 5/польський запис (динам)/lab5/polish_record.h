#pragma once
#include <iostream>
using namespace std;

int priority(char c);
bool isDigital(char c);
bool isOperand(char c);
string toPostfix(string infix);
int calculate(string expr);
