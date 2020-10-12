#include <vector>
#include "IteratorTypes.h"
#include <iostream>

struct Node
{
	int _data;
	Node* _addr;
};

//Iterable class storing indexed-arrays
template<typename T>
class ArrayStore
{
private:
	T* _children;
	unsigned int _size;

public:
	ArrayStore(T* vec, unsigned int sz) : _children(vec), _size(sz) {}

	//Creates an instance of class-specific ArrayIterator
	IIterator<T>* createIterator()
	{
		return new ArrayIterator<T>(_children, _size);
	}
};

//Another iterable class storing linked lists
template<typename T>
class ListStore
{
private:
	T** _nodes;	//ex- T=Node
	unsigned int _size;

public:
	ListStore(int* vec, unsigned int sz): _size(sz)
	{
		_nodes = new T*[_size];
		for (unsigned int i = 0; i < _size; i++)
		{
			_nodes[i] = new T();
			_nodes[i]->_data = vec[i];
			if (i >= 1)
				_nodes[i-1]->_addr = _nodes[i];
		}
		_nodes[_size - 1]->_addr = nullptr;
	}

	~ListStore()
	{
		for (unsigned int i = 0; i < _size; i++)
			delete _nodes[i];
		delete _nodes;
	}

	//Creates an instance of class-specific ListIterator
	IIterator<T>* createIterator()
	{
		return new ListIterator<T>(_nodes[0]);
	}
};

int main()
{
	//storing integers in an array class
	int arr[10] = {23, 45, 11, 65, 77, 9, 98, 33, 82, 10};
	ArrayStore<int>* arrayObj = new ArrayStore<int>(arr, sizeof(arr)/sizeof(arr[0]));
	IIterator<int>* itr = arrayObj->createIterator();

	//accessing arraystore class object using iterator
	std::cout << "ArrayIterator for ints: ";
	for (itr->First(); !itr->IsDone(); itr->Next())
	{
		std::cout << itr->CurrentItem() << " ";
	}
	std::cout << std::endl;

	//storing string in an array class
	std::string str_arr[10] = { "Fight", "Hi!", "Do", "Love", "Meet", "Keys", "CPlusPlus", "Python", "Mark", "Facebook" };
	ArrayStore<std::string>* str_arrays = new ArrayStore<std::string>(str_arr, sizeof(str_arr) / sizeof(str_arr[0]));
	IIterator<std::string>* itr2 = str_arrays->createIterator();

	//accessing arraystore class object using iterator
	std::cout << "ArrayIterator for strs: ";
	for (itr2->First(); !itr2->IsDone(); itr2->Next())
	{
		std::cout << itr2->CurrentItem().c_str() << " ";
	}
	std::cout << std::endl;

	//storing linkedlist in an array class
	ListStore<Node>* linkedlist = new ListStore<Node>(arr, sizeof(arr) / sizeof(arr[0]));
	IIterator<Node>* itr3 = linkedlist->createIterator();

	//accessing linkedlist class object using iterator
	std::cout << "ListIterator for ints: ";
	for (itr3->First(); !itr3->IsDone(); itr3->Next())
	{
		std::cout << itr3->CurrentItem()._data << " ";
	}

	std::cin.get();
	return 0;
}