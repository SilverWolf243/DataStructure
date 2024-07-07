#pragma once
template<typename T>
class DynamicArray
{
private:
	int _capacity;
	int _size;
	T*  _dataPtr;
public:
	DynamicArray() : _capacity(0), _size(0), _dataPtr(nullptr)
	{
		
	}
	
	~DynamicArray() 
	{
		if (_dataPtr)
			delete[] _dataPtr;
	}

	void Reserve(int newCapacity)
	{
		T* allocCapcityPtr = new T[newCapacity];
		::memcpy(allocCapcityPtr, _dataPtr, _capacity * sizeof(T));
		_capacity = newCapacity;

		delete[] _dataPtr;
		_dataPtr = nullptr;

		_dataPtr = allocCapcityPtr;
	}

	void PushBack(const T& data) 
	{
		int newSize = _size + 1;
		if (_capacity <= newSize)
		{
			int newCapacity = 2 * newSize;
			Reserve(newCapacity);
		}
		_dataPtr[_size] = data;
		_size = newSize;
	}

	void PopBack() 
	{
		int nextSize = _size - 1;
		_size = nextSize;
	}

	T& operator[](int index) 
	{
		return _dataPtr[index];
	}

public:
	int		Size() { return _size; }
	bool	Empty() { return _size == 0; }
	T		Front() { return _dataPtr[0]; }
};

