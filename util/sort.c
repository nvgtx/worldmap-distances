#include "../system_types.h"
#include "../system_structures.h"

uint16 sort_partition(distance* array, uint16 p, uint16 r)
{
	distance tmp;
	uint16 i=p;
	uint16 j=r-1;
	
	do
	{
		do
		{
			i++;
		}while(array[i].distance<=array[p].distance);

		do
		{
			j--;
		}while(array[j].distance>=array[p].distance);

		if(array[i].distance<array[j].distance)
		{
			tmp=array[i];
			array[i]=array[j];
			array[j]=tmp;
		}
	}while(array[i].distance<array[j].distance);

	if(array[i].distance>array[p].distance)
	{
		tmp=array[i];
		array[i]=array[r];
		array[r]=tmp;
	}
	return i;
}

void sort_quickSort(distance* array, uint16 p, uint16 r)
{
	if(p<r)
	{
		uint16 q=sort_partition(array, p, r);
		sort_quickSort(array, p, q);
		sort_quickSort(array, q+1, r);
	}
}

