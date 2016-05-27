#include "../system_types.h"
#include "geo.h"
#include "../util/math.h"

sfloat geo_distanceSphere(sfloat lat1, sfloat lon1, sfloat lat2, sfloat lon2)
{
	sfloat aHarv, cHarv;

	//earth's radius from wikipedia varies between 6,356.750 km — 6,378.135 km(˜3,949.901 — 3,963.189 miles)
	//The IUGG value for the equatorial radius of the Earth is 6378.137 km(3963.19 mile)
	const sfloat radius=6378.137; // km

	lat1*=(math_PI/180);
	lon1*=(math_PI/180);
	lat2*=(math_PI/180);
	lon2*=(math_PI/180);

	aHarv=math_pow(math_sin((lat1-lat2)/2.0), 2.0)+math_cos(lat1)*math_cos(lat2)*math_pow(math_sin((lon1-lon2)/2), 2);
	cHarv=2*math_arctan2(math_sqrt(aHarv), math_sqrt(1.0-aHarv));

	return radius*cHarv;
}

sfloat geo_distanceWGS84(sfloat lat1, sfloat lon1, sfloat lat2, sfloat lon2)
{
	sfloat result;

	sfloat iter;
	const sfloat MAXITER=100;

	sfloat r, tu1, tu2, cu1, su1, cu2, s1, b1, f1;
	sfloat x, sx, cx, sy, cy, y, sa, c2a, cz, e, c, d;
	const sfloat EPS=0.00000000005;

	lat1*=(math_PI/180);
	lon1*=(math_PI/180);
	lat2*=(math_PI/180);
	lon2*=(math_PI/180);

	// elliptic code
	const sfloat radius=(6378.137/1.852);//WGS84
	const sfloat flattening=1/298.257223563;//WGS84

	if((lat1+lat2 == 0.0) && (math_abs(lon1-lon2) == math_PI)){
		//Course and distance between antipodal points is undefined
		lat1+=0.00001;// allow algorithm to complete
	}
	if(lat1==lat2 && (lon1==lon2 || math_abs(math_abs(lon1-lon2)-2*math_PI) < EPS)){
		//Points 1 and 2 are identical- course undefined
		return 0.0;
	}
	r=1-flattening;
	tu1=r*math_tan(lat1);
	tu2=r*math_tan(lat2);
	cu1=1.0/math_sqrt(1.0+tu1*tu1);
	su1=cu1*tu1;

	cu2=1.0/math_sqrt(1.0+tu2*tu2);
	s1=cu1*cu2;
	b1=s1*tu2;
	f1=b1*tu1;
	x=lon2-lon1;
	d=x+1; // force one pass
	for(iter=1.0; (math_abs(d-x) > EPS) && (iter < MAXITER); iter++)
	{
		sx=math_sin(x);
		cx=math_cos(x);
		tu1=cu2*sx;
		tu2=b1-su1*cu2*cx;
		sy=math_sqrt(tu1*tu1+tu2*tu2);
		cy=s1*cx+f1;

		y=math_arctan2(sy, cy);
		sa=s1*sx/sy;
		c2a=1-sa*sa;
		cz=f1+f1;

		if(c2a > 0.0)
		{
			cz=cy-cz/c2a;
		}

		e=cz*cz*2.0-1.0;
		c=((-3.0*c2a+4.0)*flattening+4.0)*c2a*flattening/16.0;
		d=x;
		x=((e*cy*c+cz)*sy*c+y)*sa;
		x=(1.0-c)*x*flattening+lon2-lon1;
	}
	if(math_abs(iter-MAXITER) < EPS)
	{
		//algorithm did not converge;
		return -1.0;
	}

	x=math_sqrt((1/(r*r)-1)*c2a+1);
	x=(x-1.0)/(x+1.0);
	c=(x*x/4.0+1.0)/(1.0-x);
	d=(0.375*x*x-1.0)*x;

	result=((((sy*sy*4.0-3.0)*(1.0-2*e)*cz*d/6.0-(e*cy))*d/4.0+cz)*sy*d+y)*c*radius*r;

	return result*1.852;//km, distance conversion factor to go to physical units
}
