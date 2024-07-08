#pragma once
template<typename T>
class LinkedList
{
	struct Node 
	{
	public:
		T data;
		Node* prev;
		Node* next;

	public:
		Node(const T& data, Node* prev, Node* next) 
		{
			this->data = data;
			this->prev = prev;
			this->next = next;
		}
		Node(Node* prev, Node* next)
		{
			this->prev = prev;
			this->next = next;
		}
	};
private:
	int		_size;
	Node*	_head;
	Node*	_tail;
public:
	LinkedList() : _size(0)
	{
		_head = new Node(_tail, _head);
		_tail = new Node(_tail, _head);
	}
	~LinkedList() {}

	void PushBack(const T& data) 
	{
		Node* node = new Node(data, nullptr, nullptr);

		Node* tailNextNode = _tail->next;
		tailNextNode->prev = node;
		node->next = tailNextNode;
		_tail->next = node;
		node->prev = _tail;

		_size++;
	}

	void PushFront(const T& data) 
	{
		Node* node = new Node(data, nullptr, nullptr);

		Node* headPrevNode = _head->prev;
		headPrevNode->next = node;
		node->prev= headPrevNode;
		_head->prev = node;
		node->next = _head;

		_size++;
	}	

	void PopBack()
	{
		if (Empty())
		{
			cout << "List Size 0 Error" << endl;
			return;
		}

		Node* deleteNode = _tail->next;
		Node* deleteNodeNextNode = deleteNode->next;
		
		deleteNodeNextNode->prev = _tail;
		_tail->next = deleteNodeNextNode;

		delete deleteNode;
		_size--;
	}

	void PopFront() 
	{
		if (Empty())
		{
			cout << "List Size 0 Error" << endl;
			return;
		}

		Node* deleteNode = _head->prev;
		Node* deleteNodePrevNode = deleteNode->prev;

		deleteNodePrevNode->next = _head;
		_head->prev = deleteNodePrevNode;

		delete deleteNode;
		_size--;
	}

public:
	int		Size() { return _size; }
	bool	Empty() { return _size == 0; }

	void    Debug() 
	{
		Node* s = _head;
		while (s->prev != _tail)
		{
			Node* now = s->prev;
			cout << now->data << endl;
			s = now;
		}
	}
};