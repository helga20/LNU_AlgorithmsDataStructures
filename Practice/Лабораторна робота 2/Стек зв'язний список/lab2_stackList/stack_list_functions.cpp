#include <iostream>
#include "stack_list.h"
using namespace std;

NodeStack::NodeStack()
{
    top = nullptr;
    int size = 0;
}

NodeStack::~NodeStack()
{}

bool NodeStack::isEmpty(Node* size)
{
    if (size == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void NodeStack::push(char val)
{
    Node* elem = new Node();
    elem->value = val;
    elem->next = top;
    top = elem;
}

void NodeStack::pop()
{
    float elem;
    if (top == NULL)
    {
        cout << "Stack Underflow" << endl;
    }
    else
    {
        cout << "Pop elem: " << top->value << endl;
        top = top->next;
    }
}

void NodeStack::printOn()
{
    cout << "Stack elements: ";
    struct Node* current;
    if (top == nullptr)
    {
        cout << "Stack is empty";
    }
    else 
    {
        current = top;
        while (current != NULL) 
        {
            cout << current->value << " ";
            current = current->next;
        }
    }
    cout << endl;
}

