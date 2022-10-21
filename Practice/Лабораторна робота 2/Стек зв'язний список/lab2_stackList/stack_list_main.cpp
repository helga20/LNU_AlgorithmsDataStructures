#include <iostream>
#include "stack_list.h"
#include <stack>
using namespace std;

int main()
{
    NodeStack node1;

    node1.push('(');
    node1.push(')');
    node1.printOn();
    node1.pop();
    node1.printOn();

    system("pause");
    return 0;
}
