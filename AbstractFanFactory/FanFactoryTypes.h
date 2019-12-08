#ifndef _CEILINGFAN_FACTORY_H_
#define _CEILINGFAN_FACTORY_H_

#include "FanFactory.h"
#include "BladeTypes.h"
#include "MotorTypes.h"

class CeilingFanFactory : public FanFactory
{
public:	//methods
	void CreateBlades(std::string & spec)
	{
		Blades* blades = new LongBlades();
		spec += blades->BladeSpecs() + "\n";
	}
	void CreateMotor(std::string & spec)
	{
		Motor* mtr = new CeilingMotor();
		spec += mtr->MotorSpecs()+"\n";
	}
	void CreateBody(std::string & spec)
	{
		spec += "Ceiling Fan: These are most commonly used for home usage.\n";
	}
};

class TableFanFactory : public FanFactory
{
public:	//methods
	void CreateBlades(std::string & spec)
	{
		Blades* blades = new MidBlades();
		spec += blades->BladeSpecs() + "\n";
	}
	void CreateMotor(std::string & spec)
	{
		Motor* mtr = new PedestalMotor();
		spec += mtr->MotorSpecs() + "\n";
	}
	void CreateBody(std::string & spec)
	{
		spec += "Pedestal Fan: These are also known as 'Stand Fans' and commonly used for parties and marriages.\n";
	}
};

class CoachFanFactory : public FanFactory
{
public:	//methods
	void CreateBlades(std::string & spec)
	{
		Blades* blades = new ShortBlades();
		spec += blades->BladeSpecs() + "\n";
	}
	void CreateMotor(std::string & spec)
	{
		Motor* mtr = new CoachMotor();
		spec += mtr->MotorSpecs() + "\n";
	}
	void CreateBody(std::string & spec)
	{
		spec += "Coach Fan: These are most commonly used for buses and cars.\n";
	}
};

#endif
