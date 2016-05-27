#include "../system_types.h"
#include "../system_structures.h"
#include "coordinate.h"

sfloat coordinate_convertToDec(const uint8 degree, const uint8 minute, const uint8 second, const bool southWest)
{
	sfloat result=(sfloat)degree;

	if(minute>0)
	{
		result+=(sfloat)minute/(sfloat)60.0;
	}
	if(second>0)
	{
		result+=(sfloat)second/(sfloat)3600.0;
	}

	if(southWest==true)
	{
		result*=(sfloat)(-1.0);
	}
	
	return result;
}
