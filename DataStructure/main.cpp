#include "pch.h"
#include "LinkedList.h"
int main() 
{
	LinkedList<int> l;

	l.PushBack(2);
	l.PushBack(3);
	l.PushFront(1);
	l.PopBack();
	l.PopFront();
	l.Debug();

	return 0;
}