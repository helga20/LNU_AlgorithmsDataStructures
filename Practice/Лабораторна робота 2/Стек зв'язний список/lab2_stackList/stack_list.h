#pragma once
#include <iostream>
using namespace std;

class NodeStack
{
private:
    struct Node
    {
        char value;
        Node* next;
    };
    Node* top;
public:
    NodeStack();
    ~NodeStack();

    void printOn();
    bool isEmpty(Node*);
    void push(char val);
    void pop();
};
