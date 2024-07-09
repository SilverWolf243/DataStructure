#include "pch.h"
#include "Stack.h"
int main() 
{
	Stack<int> s;
	s.Push(3);
	s.Push(4);
	s.Push(1);
	s.Push(2);

	while (s.Empty() == false)
	{
		cout << s.Top() << endl;
		s.Pop();
	}
	return 0;
}