#pragma once

#include <vector>
#include <algorithm>

class IStrategy
{
public:
	virtual void sort(std::vector<int>& vc) = 0;
};

class AscendingStrategy: public IStrategy
{
public:
	void sort(std::vector<int>& vc)
	{
		std::sort(vc.begin(), vc.end());
	}
};

class AscendingEvenFirstStrategy : public IStrategy
{
public:
	void sort(std::vector<int>& vc)
	{
		std::vector<int> eVC;
		std::vector<int> oVC;
		for (std::vector<int>::iterator itr = vc.begin(); itr != vc.end(); itr++)
		{
			if (*itr % 2 == 0)
				eVC.push_back(*itr);
			else
				oVC.push_back(*itr);
		}

		std::sort(eVC.begin(), eVC.end());
		std::sort(oVC.begin(), oVC.end()); 
		
		eVC.insert(eVC.end(), oVC.begin(), oVC.end());
		vc = eVC;
	}
};

class AscendingOddFirstStrategy : public IStrategy
{
	void sort(std::vector<int>& vc)
	{
		std::vector<int> eVC;
		std::vector<int> oVC;
		for (std::vector<int>::iterator itr = vc.begin(); itr != vc.end(); itr++)
		{
			if (*itr % 2 == 0)
				eVC.push_back(*itr);
			else
				oVC.push_back(*itr);
		}

		std::sort(eVC.begin(), eVC.end());
		std::sort(oVC.begin(), oVC.end());

		oVC.insert(oVC.end(), eVC.begin(), eVC.end());
		vc = oVC;
	}
};

class DescendingOddFirstStrategy : public IStrategy
{
	void sort(std::vector<int>& vc)
	{
		std::vector<int> eVC;
		std::vector<int> oVC;
		for (std::vector<int>::iterator itr = vc.begin(); itr != vc.end(); itr++)
		{
			if (*itr % 2 == 0)
				eVC.push_back(*itr);
			else
				oVC.push_back(*itr);
		}

		std::sort(eVC.begin(), eVC.end());
		std::reverse(eVC.begin(), eVC.end());

		std::sort(oVC.begin(), oVC.end());
		std::reverse(oVC.begin(), oVC.end());

		oVC.insert(oVC.end(), eVC.begin(), eVC.end());
		vc = oVC;
	}
};