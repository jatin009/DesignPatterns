#include "AlmirahDecoratorTypes.h"
#include <iostream>

int main()
{
	char choice;

	std::cout << "On Almirah Door, you would like to:\na. have a mirror,\nb. have some nice paintings,\nc. have some good thoughts,\nd. have both mirror(on left) and some decoration(on right),\ne. exit" << std::endl;

	std::cin >> choice;

	IAlmirahDoor* withMirrorDoor = new AlmirahDoorMirrorDecorator(new AlmirahDoor());
	IAlmirahDoor* withPaintingsDoor = new AlmirahDoorPaintingsDecorator(new AlmirahDoor());
	IAlmirahDoor* withThoughtsDoor = new AlmirahDoorPosterDecorator(new AlmirahDoor());
	IAlmirahDoor* withMirrorPaintingsDoor = new AlmirahDoorMirrorDecorator(new AlmirahDoorPaintingsDecorator(new AlmirahDoor()));


	while (choice != 'e')
	{
		if (choice == 'a')
		{
			withMirrorDoor->KeepSafe();
		}
		else if (choice == 'b')
		{
			withPaintingsDoor->KeepSafe();
		}
		else if (choice == 'c')
		{
			withThoughtsDoor->KeepSafe();
		}
		else if (choice == 'd')
		{
			withMirrorPaintingsDoor->KeepSafe();
		}
		else if (choice == 'e')
		{
			break;
		}

		std::cout << "On Almirah Door, you would like to:\na. have a mirror,\nb. have some nice paintings,\nc. have some good thoughts,\nd. have both mirror(on left) and some decoration(on right),\ne. exit" << std::endl;

		std::cin >> choice;
	}

	delete withMirrorDoor;
	delete withPaintingsDoor;
	delete withThoughtsDoor;
	delete withMirrorPaintingsDoor;

	std::cin.get();

	return 0;
}