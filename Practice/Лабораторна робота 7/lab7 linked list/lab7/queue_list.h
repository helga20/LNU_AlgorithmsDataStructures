#pragma once
class LinkedList
{
public:
	int data;
	int pri;

	LinkedList* next;
	LinkedList(int data, int pri)
	{
		this->data = data;
		this->pri = pri;
		this->next = nullptr;
	}
	~LinkedList() {}
};

class Priority_Queue
{
	LinkedList* head;
	LinkedList* tail;

public:
	Priority_Queue()
	{
		head = nullptr;
		tail = nullptr;
	}

	~Priority_Queue() {}
	bool isEmpty();
	int getSize();
	void push(int data, int pri);
	void pop();
	void print();
};