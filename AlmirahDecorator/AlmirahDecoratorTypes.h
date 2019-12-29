#ifndef _ALMIRAH_DECORATOR_TYPES_H_
#define _ALMIRAH_DECORATOR_TYPES_H_

#include <iostream>

class IAlmirahDoor
{
public:
	virtual ~IAlmirahDoor() {}
	virtual void KeepSafe() = 0;
};

class AlmirahDoor: public IAlmirahDoor
{
public:
	~AlmirahDoor() { std::cout << "Dtor AlmirahDoor" << std::endl; }

	void KeepSafe()
	{
		std::cout << "Almirah Door's prime functionality to keep things safe." << std::endl;
	}
};

class AlmirahDoorDecorator : public IAlmirahDoor
{
private:
	IAlmirahDoor * m_Component;

public:
	AlmirahDoorDecorator(IAlmirahDoor* component)
	{
		m_Component = component;
	}

	~AlmirahDoorDecorator() { std::cout << "Dtor AlmirahDoorDecorator" << std::endl; }

	void KeepSafe()
	{
		m_Component->KeepSafe();
	}
};

class AlmirahDoorMirrorDecorator : public AlmirahDoorDecorator
{
public:

	AlmirahDoorMirrorDecorator(IAlmirahDoor* door): AlmirahDoorDecorator(door){}
	~AlmirahDoorMirrorDecorator() { std::cout << "Dtor AlmirahDoorMirrorDecorator" << std::endl; }

	void KeepSafe()
	{
		AlmirahDoorDecorator::KeepSafe();
		SeeYourSelf();
	}
private:
	void SeeYourSelf()
	{
		std::cout << "Along with the keeping safe, also look how you look today." << std::endl;
	}
};

class AlmirahDoorPaintingsDecorator : public AlmirahDoorDecorator
{
public:
	
	AlmirahDoorPaintingsDecorator(IAlmirahDoor* door) : AlmirahDoorDecorator(door) {}
	~AlmirahDoorPaintingsDecorator() { std::cout << "Dtor AlmirahDoorPaintingsDecorator" << std::endl; }

	void KeepSafe()
	{
		AlmirahDoorDecorator::KeepSafe();
		DecorateYourRoom();
	}
private:
	void DecorateYourRoom()
	{
		std::cout << "Along with covering your belongings, also have nice paintings to decorate your room." << std::endl;
	}
};

class AlmirahDoorPosterDecorator : public AlmirahDoorDecorator
{
public:

	AlmirahDoorPosterDecorator(IAlmirahDoor* door) : AlmirahDoorDecorator(door) {}
	~AlmirahDoorPosterDecorator() { std::cout << "Dtor AlmirahDoorPosterDecorator" << std::endl; }

	void KeepSafe()
	{
		AlmirahDoorDecorator::KeepSafe();
		HaveGoodThoughts();
	}
private:
	void HaveGoodThoughts()
	{
		std::cout << "Instead of looking at plain door, have some good thoughts to motivate you everyday!" << std::endl;
	}
};

#endif	//_ALMIRAH_DECORATOR_TYPES_H_
