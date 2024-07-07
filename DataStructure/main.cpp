#include "pch.h"
#include "Deque.h"
int main() 
{
	Deque<int> dq;
	dq.PushBack(1);
	dq.PushBack(2);
	dq.PushBack(3);
	dq.PushFront(4);

	for (int i = 0; i < dq.Size(); i++) 
	{
		cout << dq[i] << endl;
	}
	return 0;
}