#ifndef	_SYSTEM_STRUCTURES_H_
#define _SYSTEM_STRUCTURES_H_

typedef struct coordinate {
	sfloat latitude;
	sfloat longitude;
}coordinate;

typedef struct distance {
	uint8 point1;
	uint8 point2;
	sfloat distance;
}distance;

#endif /* _SYSTEM_STRUCTURES_H_ */
