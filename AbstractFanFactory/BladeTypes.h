#ifndef _BLADE_TYPES_H_
#define _BLADE_TYPES_H_

#include "Blades.h"

class LongBlades: public Blades
{
public:
	LongBlades() : Blades(TRAPEZIUM, 29) {}
};

class MidBlades : public Blades
{
public:
	MidBlades() : Blades(TRIANGULAR, 14) {}
};

class ShortBlades : public Blades
{
public:
	ShortBlades() : Blades(CURVY, 6) {}
};

#endif