#include "pch.h"
#include "CppUnitTest.h"
#include <queue>
#include <iostream>
#include <climits>

using namespace std;

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

Priority_Queue::Priority_Queue(int size)
{
	A = new prior_Queue[size];
	capacity = size;
	last = 0;
}

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

int main()
{
	Priority_Queue q(5);

	q.isEmpty();
	system("pause");
	cout << "\n";

	q.push(20, 8);
	q.push(30, 7);
	q.push(40, 9);
	q.push(50, 14);
	q.push(55, 14);

	q.isFull();
	system("pause");
	cout << "\n";

	q.pop();
	q.pop();
	system("pause");
	cout << "\n";

	q.push(45, 3);

	q.ptintOn();

	q.isEmpty();

	system("pause");
	return 0;
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:	
		TEST_METHOD(test_full)
		{
			Priority_Queue q(1);
			q.push(1, 2);
			Assert::IsTrue(q.isFull());
		}

		TEST_METHOD(test_empty)
		{
			Priority_Queue q(0);
			Assert::IsTrue(q.isEmpty());
		}

		TEST_METHOD(test_push)
		{
			bool passed = true;

			Priority_Queue q(3);
			q.push(1, 3);
			q.push(2, 2);
			q.push(9, 1);
			passed &= !q.isEmpty();

			Assert::IsTrue(passed);
		}

		TEST_METHOD(test_pop)
		{
			bool passed = true;

			Priority_Queue q(2);
			q.push(1, 3);
			q.push(2, 2);
			q.pop();
			q.pop();
			passed &= q.isEmpty();

			Assert::IsTrue(passed);
		}
	};
}


