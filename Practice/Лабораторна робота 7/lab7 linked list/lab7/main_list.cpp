#include"queue_list.h"
#include <iostream>
#include <queue>
using namespace std;

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