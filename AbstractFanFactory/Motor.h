#ifndef _MOTOR_H_
#define _MOTOR_H_

#include <string>

class Motor
{
protected:	//members
	
	enum Type
	{
		AC,
		DC
	};

	Type m_eType;
	int m_Power;	//in watts
	int m_Voltage;	//in vols

public:		//methods
	Motor(Type e, int power, int volts): m_eType(e), m_Power(power), m_Voltage(volts) {}

	std::string MotorSpecs()
	{
		std::string type = (m_eType == AC) ? "Motor Specs: AC, " : "Motor Specs: DC, ";
		type += "Power (in watts): " + std::to_string(m_Power) + ", ";
		type += "Voltage (in volts): " + std::to_string(m_Voltage);
		return type;
	}
};

#endif
