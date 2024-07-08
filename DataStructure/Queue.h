#pragma once
template<typename T>
class Queue
{
private:
	int		_startIndex;
	int		_endIndex;
	int		_size;
	int		_capacity;
	T*		_data;

public:
	Queue() : _startIndex(0), _endIndex(0), _size(0), _data(nullptr) {}
	~Queue() {}

	void Push(const T& data) 
	{
		int nextSize = _size + 1;
		if (_capacity <= nextSize)
		{
			int newCapacity = 2 * nextSize;
			Reserve(newCapacity);
		}
		_data[_endIndex] = data;
		_endIndex = (_endIndex + 1) % _capacity;
		_size = nextSize;
	}

	void Pop() 
	{
		if (Empty())
		{
			cout << "Queue Size 0 Error" << endl;
			return;
		}

		int nextSize = _size - 1;
		_startIndex = (_startIndex + 1) % _capacity;
		_size = nextSize;
	}

	void Reserve(int newCapacity)
	{
		T* allocCapcityPtr = new T[newCapacity];
		
		for (int i = 0; i < _size; i++) 
			allocCapcityPtr[i] = _data[(i + _startIndex) % _capacity];

		delete[] _data;
		_data = allocCapcityPtr;

		_startIndex = 0;
		_endIndex = _size;
		_capacity = newCapacity;
	}

public:
	int		Size() { return _size; }
	bool	Empty() { return _size == 0; }
	T&		Front() { return _data[_startIndex]; }
};

