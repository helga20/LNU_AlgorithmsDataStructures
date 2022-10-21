#include"queue_list.h"
#include <iostream>
#include <queue>

using namespace std;

bool test_empty()
{
	bool passed = true;

	Priority_Queue q;
	passed &= q.isEmpty();

	return passed;
}

bool test_push()
{
	bool passed = true;

	Priority_Queue q;
	q.push(1, 3);
	q.push(2, 2);
	q.push(9, 1);
	passed &= !q.isEmpty();
	return passed;
}

bool test_pop()
{
	bool passed = true;

	Priority_Queue q;
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

	cout << (test_empty() ? "\nTest (isEmpty) passed\n" : "\nTest (isEmpty) failed\n") << endl;
	cout << "_________________________\n\n";

	cout << (test_push() ? "\nTest (push) passed\n" : "\nTest (push) failed\n") << endl;
	cout << "_________________________\n\n";

	cout << (test_pop() ? "\nTest (pop) passed\n" : "\nTest (pop) failed\n") << endl;
	cout << "_________________________\n";

	cout << (test_size() ? "\nTest (size) passed\n" : "\nTest (size) failed\n") << endl;
	cout << "_________________________\n";



	/*Priority_Queue q;

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

	q.isEmpty();*/

	system("pause");
	return 0;
}