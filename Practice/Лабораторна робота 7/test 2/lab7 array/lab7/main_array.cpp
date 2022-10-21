#include <climits>
#include"queue_array.h"
#include <iostream>
using namespace std;

bool test_full()
{
	bool passed = true;

	Priority_Queue q(1);
	q.push(1, 2);
	passed &= q.isFull();

	return passed;
}

bool test_empty()
{
	bool passed = true;

	Priority_Queue q(0);
	passed &= q.isEmpty();

	return passed;
}

bool test_push()
{
	bool passed = true;

	Priority_Queue q(3);
	q.push(1, 3);
	q.push(2, 2);
	q.push(9, 1);
	passed &= !q.isEmpty();
	return passed;
}

bool test_pop()
{
	bool passed = true;

	Priority_Queue q(3);
	q.push(1, 3);
	q.push(2, 2);
	q.push(9, 1);
	q.pop();
	q.pop();
	q.pop();
	passed &= q.isEmpty();

	return passed;
}

int main()
{
	cout << " Tests: \n";
	cout << "_ _ _ _ _ _ _ _ _ _ _ _ _\n\n";

	cout << (test_full() ? "\nTest (isFull) passed\n" : "\nTest (isFull) failed\n") << endl;
	cout << "_________________________\n";

	cout << (test_empty() ? "\nTest (isEmpty) passed\n" : "\nTest (isEmpty) failed\n") << endl;
	cout << "_________________________\n\n";

	cout << (test_push() ? "\nTest (push) passed\n" : "\nTest (push) failed\n") << endl;
	cout << "_________________________\n\n";

	cout << (test_pop() ? "\nTest (pop) passed\n" : "\nTest (pop) failed\n") << endl;
	cout << "_________________________\n";


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