#pragma once

//Interface IIterator
template <typename T>
class IIterator
{
public:
	virtual T First() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() = 0;
	virtual T CurrentItem() = 0;
};

//Default NullIterator class
template <typename T>
class NullIterator : public IIterator<T>
{
public:
	T First() { return nullptr; }
	void Next() { return nullptr; }
	bool IsDone() { return true; }
	T CurrentItem() { return nullptr; }
};

//Iterator class accessing indexed-arrays
template <typename T>
class ArrayIterator : public IIterator<T>
{
private:
	T* _iterable;
	unsigned int _arraySize;
	unsigned int _currentIdx;

public:
	//Takes complete array as an argument and its size
	ArrayIterator(T* iterable, unsigned int arraySize) : _iterable(iterable), _arraySize(arraySize), _currentIdx(0) {}
	T First() 
	{
		if (_arraySize > 0)
			return _iterable[0];
	}
	bool IsDone() { return (_currentIdx >= _arraySize);	}
	void Next() 
	{
		if (_currentIdx < _arraySize)
			_currentIdx += 1;
	}
	T CurrentItem() { return _iterable[_currentIdx]; }
};

//Iterator class accessing linked lists
template <typename T>
class ListIterator : public IIterator<T>
{
private:
	T* _currentNode;	// ex- T=Node

public:
	//Takes only the first element of linked list as argument
	//since all others can be accessed from the addresses
	ListIterator(T* currentNode) : _currentNode(currentNode){}
	T First()
	{
		return *_currentNode;
	}
	bool IsDone() 
	{ 
		return (_currentNode == nullptr);
	}
	void Next()
	{
		_currentNode = _currentNode->_addr;
	}
	T CurrentItem() 
	{ 
		return *_currentNode;
	}
};
