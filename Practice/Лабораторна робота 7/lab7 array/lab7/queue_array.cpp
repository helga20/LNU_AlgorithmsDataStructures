#include "queue_array.h"
#include <iostream>
#include <queue>
using namespace std;

Priority_Queue::Priority_Queue(int size)
{
	A = new prior_Queue[size];
	capacity = size;
	last = 0;
}

//int Priority_Queue::getSize()
//{
//	cout << "Queue size:" << capacity << endl;
//	return capacity;
//}

bool Priority_Queue::isFull()
{
	if (last == capacity)
	{
		cout << "Queue is full\n";
		return true;
	}
	else
	{
		return false;
	}
}

void Priority_Queue::push(int data, int pri)
{
	if (isFull())
	{
		return;
	}
	cout << "Push: " << data << " Priority: " << pri << endl;
	A[last].data = data;
	A[last].pri = pri;
	last++;
}

bool Priority_Queue::isEmpty()
{
	if (last == 0)
	{
		cout << "\nQueue is empty\n";
		return true;
	}
	else
	{
		cout << "\nQueue is not empty\n";
		return false;
	}
}

void Priority_Queue::pop()
{
	if (isEmpty())
	{
			return;
	}

	int maxp = INT_MIN;
	int k;
	for (int i = 0; i < last; ++i)
	{
		if (maxp < A[i].pri)
		{
			maxp = A[i].pri;
			k = i;
		}
	}

	cout << "Pop: " << A[k].data << " Priority(max): " << maxp << endl;
	for (int i = k; i < last - 1; ++i)
	{
		A[i] = A[i + 1];
	}
	last--;
}

void Priority_Queue::ptintOn()
{
	cout << "\nPrinting queue: \n";
	for (int i = 0; i < last; ++i)
	{
		cout << "Data: " << A[i].data << " Priority: " << A[i].pri << endl;
	}
}
