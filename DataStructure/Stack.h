#pragma once
#include "DynamicArray.h"
/*
	이전에 구현한 DynamicArray를 이용하여 구현
*/
template<typename T>
class Stack
{
private:
	DynamicArray<T>		_array;
public:
	Stack()
	{
	
	}

	~Stack() 
	{
	
	}	
	
	void Push(const T& data) 
	{
		_array.PushBack(data);
	}

	void Pop() 
	{
		_array.PopBack();
	}

	T& Top() 
	{
		return _array[_array.Size() - 1];
	}

public:
	bool Empty() { return _array.Empty(); }
	int	 Size()  { return _array.Size(); }
};

