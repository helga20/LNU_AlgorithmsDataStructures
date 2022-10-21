#pragma once
#include <iostream>
using namespace std;

int priority(char c);
bool isDigital(char c);
string toPostfix(string source);
int calculate(string expr);
