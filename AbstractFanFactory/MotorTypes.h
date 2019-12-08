#ifndef _MOTORTYPES_H_
#define _MOTORTYPES_H_

#include "Motor.h"

class CeilingMotor : public Motor
{
public:
	CeilingMotor() : Motor(AC, 20, 240) {}
};

class PedestalMotor : public Motor
{
public:
	PedestalMotor() : Motor(AC, 16, 240) {}
};

class CoachMotor : public Motor
{
public:
	CoachMotor() : Motor(DC, 20, 100) {}
};

#endif
