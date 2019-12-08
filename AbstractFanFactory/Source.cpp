#include <iostream>
#include <string>
#include "FanFactoryTypes.h"

void CreateFan(FanFactory* fan, std::string& specOutput)
{
	fan->CreateBody(specOutput);
	fan->CreateBlades(specOutput);
	fan->CreateMotor(specOutput);
}

int main()
{
	std::string type, outputstr;

	do
	{
		outputstr = "";
		std::cout << "\n\nEnter the type of fan you wish to create, 'ceiling' or 'table' or 'coach'; or 'quit' to exit: ";
		std::cin >> type;
		if (type == "ceiling")
		{
			CreateFan(new CeilingFanFactory(), outputstr);
		}
		else if (type == "table")
		{
			CreateFan(new TableFanFactory(), outputstr);
		}
		else if (type == "coach")
		{
			CreateFan(new CoachFanFactory(), outputstr);
		}
		std::cout << outputstr;
	} while (type != "quit");

	std::cin.get();
	
	return 0;
}