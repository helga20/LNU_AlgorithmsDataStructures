#include <climits>
#include"queue_array.h"
#include <iostream>
using namespace std;

int main()
{
	Priority_Queue q(5);

	q.isEmpty();
	system("pause");
	cout << "\n";

	//q.push(10, 5);
	q.push(20, 8);
	q.push(30, 7);
	q.push(40, 9);
	q.push(50, 14);
	q.push(55, 14);

	q.isFull();
	//q.getSize();
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