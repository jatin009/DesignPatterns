#ifndef _FAN_FACTORY_H_
#define _FAN_FACTORY_H_

class FanFactory
{
public:
	virtual void CreateBlades(std::string & spec) = 0;
	virtual void CreateMotor(std::string & spec) = 0;
	virtual void CreateBody(std::string & spec) = 0;
};

#endif
