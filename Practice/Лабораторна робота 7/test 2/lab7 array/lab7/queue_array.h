#pragma once
struct prior_Queue
{
	int data;
	int pri;
};

class Priority_Queue
{
	prior_Queue* A;
	int capacity;
	int last;
public:

	Priority_Queue(int size);
	bool isFull();
	void push(int data, int pri);
	bool isEmpty();
	void pop();
	void ptintOn();
};
