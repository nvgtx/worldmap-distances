#include <stdio.h>

#include "../system_types.h"
#include "../system_structures.h"
#include "print.h"

void print_coordinates(const coordinate* array, const uint8 length)
{
	uint8 i;
	for(i=0; i<length; i++)
	{
		printf("%2d\t%Lf\t%Lf\n", i+1, array[i].latitude, array[i].longitude);
	}
}

void print_distances(const distance* array, const uint16 length)
{
	uint16 i;

	for(i=0; i<length; i++)
	{
		if(array[i].distance!=-1.0 && array[i].distance!=0.0)
		{
			printf("distance %2d-%2d:\t%10.3Lfkm\n", array[i].point1, array[i].point2, array[i].distance);
			//printf("distance %2d-%2d:\t%.50Lfkm\n", array[i].point1, array[i].point2, array[i].distance);
		}
	}
}
