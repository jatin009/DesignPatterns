#ifndef _BLADES_H_
#define _BLADES_H_

#include <string>

class Blades
{
protected:	//members
	
	enum BladesType {
		TRAPEZIUM,
		CURVY,
		TRIANGULAR,
		LONG
	};

	BladesType m_eType;
	int m_length;	//in inches

public:	//methods
	
	Blades(BladesType e, int l) : m_eType(e), m_length(l) {}

	std::string BladeSpecs()
	{
		std::string strType = "Blade specs: ";
		switch (m_eType)
		{
		case TRAPEZIUM:
			strType += "Shape: Trapezium, ";
			break;
		case CURVY:
			strType += "Shape: Curvy, ";
			break;
		case TRIANGULAR:
			strType += "Shape: Triangular, ";
			break;
		case LONG:
			strType += "Shape: Long, ";
			break;
		default:
			break;
		}
		return strType + "Length (in inches) = "+ std::to_string(m_length);
	}
};

#endif