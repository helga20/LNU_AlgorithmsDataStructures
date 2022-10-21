#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>
#include <queue>
using namespace std;

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

int main()
{
	Priority_Queue q;

	q.isEmpty();
	system("pause");
	cout << "\n";

	q.push(10, 5);
	q.push(20, 8);
	q.push(30, 7);
	q.push(40, 9);
	q.push(50, 14);

	q.getSize();
	system("pause");
	cout << "\n";

	q.pop();
	q.pop();
	q.getSize();
	system("pause");
	cout << "\n";

	q.push(45, 3);

	q.print();
	q.getSize();

	q.isEmpty();

	system("pause");
	return 0;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(test_Empty)
		{
			Priority_Queue q;
			Assert::IsTrue(q.isEmpty());
		}

		TEST_METHOD(test_Push)
		{
			bool passed = true;

			Priority_Queue q;
			q.push(1, 3);
			q.push(2, 2);
			q.push(9, 1);
			passed &= !q.isEmpty();

			Assert::IsTrue(passed);
		}

		TEST_METHOD(test_Pop)
		{
			bool passed = true;

			Priority_Queue q;
			q.push(1, 3);
			q.push(2, 2);
			q.pop();
			q.pop();
			passed &= q.isEmpty();

			Assert::IsTrue(passed);
		}
		TEST_METHOD(test_Size)
		{
			Priority_Queue q;
			q.push(1, 3);
			q.push(2, 2);
			q.push(9, 1);

			Assert::AreEqual(3, q.getSize());
		}
	};
}
