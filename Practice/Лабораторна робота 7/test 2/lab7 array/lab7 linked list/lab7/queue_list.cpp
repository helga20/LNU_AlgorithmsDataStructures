#include"queue_list.h"
#include <iostream>
#include <queue>
using namespace std;

bool Priority_Queue::isEmpty()
{
	if (head == nullptr)
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

int  Priority_Queue::getSize()
{
	int count = 0;
	LinkedList* temp = head;
	while (temp != nullptr)
	{
		count++;
		temp = temp->next;

	}
	cout << "Queue size:" << count << endl;
	return count;
}

void Priority_Queue::push(int data, int pri)
{
	LinkedList* newnode = new LinkedList(data, pri);

	cout << "Push: " << data << " Priority: " << pri << endl;
	if (head == nullptr)
	{
		head = newnode;
		tail = newnode;
		return;
	}
	tail->next = newnode;
	tail = newnode;
}

void Priority_Queue::pop()
{
	LinkedList* temp = head;
	LinkedList* maxptr = head;

	while (temp != nullptr)
	{
		if (maxptr->pri < temp->pri)
		{
			maxptr = temp;
		}
		temp = temp->next;
	}

	cout << "\nPop: " << maxptr->data << " Priority: " << maxptr->pri << endl;

	if (head->next == nullptr)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		return;
	}

	if (maxptr == head)
	{
		head = head->next;
		delete maxptr;
		return;
	}

	temp = head;

	while (temp->next != maxptr)
	{
		temp = temp->next;
	}

	if (maxptr == tail)
	tail = temp;
	temp->next = maxptr->next;
	delete maxptr;
}

void Priority_Queue::print()
{
	LinkedList* temp = head;
	cout << "\nPrinting the values of the Queue: \n";
	while (temp != nullptr)
	{
		cout << "Data: " << temp->data << " Priority: " << temp->pri << endl;
		temp = temp->next;
	}
}

