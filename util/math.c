#include <math.h>

#include "../system_types.h"
#include "math.h"

const sfloat math_PI=M_PI;

sfloat math_sqrt(const sfloat val)
{
	return sqrtl(val);
}

sfloat math_abs(const sfloat val)
{
	return fabsl(val);
}

sfloat math_floor(const sfloat val)
{
	return floorl(val);
}

sfloat math_pow(const sfloat val1, const sfloat val2)
{
	return powl(val1, val2);
}

sfloat math_sin(const sfloat val)
{
	return sinl(val);
}

sfloat math_cos(const sfloat val)
{
	return cosl(val);
}

sfloat math_tan(const sfloat val)
{
	return tanl(val);
}

sfloat math_arcsin(const sfloat val)
{
	return asinl(val);
}

sfloat math_arccos(const sfloat val)
{
	return acosl(val);
}

sfloat math_arctan(const sfloat val)
{
	return atanl(val);
}

sfloat math_arctan2(const sfloat val1, const sfloat val2)
{
	return atan2l(val1, val2);
}


