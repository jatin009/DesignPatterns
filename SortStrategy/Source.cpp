#include <iostream>
#include "SortStrategy.h"

class Client
{
private:
	IStrategy * _stObj;

public:

	Client(): _stObj(nullptr) {}
	Client(IStrategy* st) : _stObj(st) {}

	void SetStrategy(IStrategy* st)
	{
		_stObj = st;
	}

	void Sort(std::vector<int>& vc)
	{
		_stObj->sort(vc);
	}
};

void print(const std::vector<int>& vc)
{
	for (int i = 0; i < vc.size(); i++)
		std::cout << vc[i] << ", ";
	std::cout << std::endl;
}

int main()
{
	std::cout << "We have a list of numbers: 2, 34, 12, 65, 79, 98, 67, 44, 29, 80, 56, 49, 11, 77" << std::endl;
	std::vector<int> vc = { 2, 34, 12, 65, 79, 98, 67, 44, 29, 80, 56, 49, 11, 77 };

	Client cl;
	char c;

	do
	{
		std::cout << "Enter options to sort in the desired way: \na. ascending\nb. ascending-evenfirst\nc. ascending-oddfirst\nd. descending-oddfirst \nx. exit" << std::endl;
		std::cin >> c;

		IStrategy* concreteStrategy = nullptr;
		if (c == 'a')
			concreteStrategy = new AscendingStrategy();
		else if (c == 'b')
			concreteStrategy = new AscendingEvenFirstStrategy();
		else if (c == 'c')
			concreteStrategy = new AscendingOddFirstStrategy();
		else if (c == 'd')
			concreteStrategy = new DescendingOddFirstStrategy();

		if (concreteStrategy)
		{
			cl.SetStrategy(concreteStrategy);
			cl.Sort(vc);

			print(vc);
			delete concreteStrategy;
		}
	} while (c != 'x');

	return 0;
}