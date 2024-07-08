#include "pch.h"
#include "Queue.h"
int main() 
{
	Queue<int> l;
	l.Push(3);
	l.Push(4);
	l.Push(1);
	l.Push(2);

	while (l.Empty() == false)
	{
		cout << l.Front() << endl;
		l.Pop();
	}
	return 0;
}