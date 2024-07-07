#pragma once
template<typename T>
class Deque
{
private:
	int _frontIndex;
	int _backIndex;
	int _capacity;
	int _size;
	T*  _dataPtr;
public:
	Deque() : _frontIndex(0), _backIndex(0), _dataPtr(nullptr), _size(0)
	{
	
	}

	~Deque() 
	{
		if (_dataPtr)
			delete[] _dataPtr;
	}

	void PushBack(const T& data) 
	{
		int newSize = _size + 1;
		if (_capacity <= newSize)
		{
			int newCapacity = newSize * 2;
			Reserve(newCapacity);
		}

		_dataPtr[_backIndex] = data;
		_backIndex = (_backIndex + 1) % _capacity;
		_size = newSize;
	}

	void PushFront(const T& data)
	{
		int newSize = _size + 1;
		if (_capacity <= newSize) 
		{
			int newCapacity = 2 * newSize;
			Reserve(newCapacity);
		}

		_frontIndex = (_frontIndex - 1 + _capacity) % _capacity;
		_dataPtr[_frontIndex] = data;
		_size = newSize;
	}

	void PopFront() 
	{
		int newSize = _size - 1;
		_frontIndex = (_frontIndex + 1) % _capacity;
		_size = newSize;
	}

	void PopBack() 
	{
		int newSize = _size - 1;
		_backIndex = (_backIndex - 1 + _capacity) % _capacity;
		_size = newSize;
	}

	T& operator[](int index) 
	{
		int i = (_frontIndex + index) % _capacity;
		return _dataPtr[i];
	}

private:
	void Reserve(int newCapacity)
	{
		T* allocCapacity = new T[newCapacity];
		for (int i = 0; i < _size; i++)
		{
			int index = (_frontIndex + i) % _capacity;
			allocCapacity[i] = _dataPtr[index];
		}
		if (_dataPtr)
			delete[] _dataPtr;

		_dataPtr = nullptr;
		_dataPtr = allocCapacity;
		_capacity = newCapacity;
		_frontIndex = 0;
		_backIndex = _size;
	}

public:
	int  Size() { return _size; }
	bool Empty() { return _size == 0; }
};

