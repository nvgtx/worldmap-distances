#include "system_types.h"
#include "system_structures.h"
#include "core/geo.h"
#include "core/graph.h"
#include "util/sort.h"
#include "util/print.h"
#include "util/coordinate.h"
#include "util/kml.h"

void init(coordinate* array)
{
	//20° 32' 42'' N - 144° 53' 37'' O
	array[0].latitude=coordinate_convertToDec(20, 32, 42, false);
	array[0].longitude=coordinate_convertToDec(144, 53, 37, false);

	//34° 22' 55'' N - 109° 15' 13'' O
	array[1].latitude=coordinate_convertToDec(34, 22, 55, false);
	array[1].longitude=coordinate_convertToDec(109, 15, 13, false);

	//33° 47' 58'' S - 25° 46' 11'' O
	array[2].latitude=coordinate_convertToDec(33, 47, 58, true);
	array[2].longitude=coordinate_convertToDec(25, 46, 11, false);

	//23° 22' 15'' S - 149° 31' 44'' W
	array[3].latitude=coordinate_convertToDec(23, 22, 15, true);
	array[3].longitude=coordinate_convertToDec(149, 31, 44, true);

	//05° 58' 03'' N - 62° 32' 08'' W
	array[4].latitude=coordinate_convertToDec(5, 58, 3, false);
	array[4].longitude=coordinate_convertToDec(62, 32, 8, true);

	//23° 52' 11'' N - 166° 17' 04'' W
	array[5].latitude=coordinate_convertToDec(23, 52, 11, false);
	array[5].longitude=coordinate_convertToDec(166, 17, 4, true);

	//06° 06' 10'' S - 105° 25' 23'' O
	array[6].latitude=coordinate_convertToDec(6, 6, 10, true);
	array[6].longitude=coordinate_convertToDec(105, 25, 23, false);

	//38° 43' 43'' S - 77° 31' 33'' O
	array[7].latitude=coordinate_convertToDec(38, 43, 43, true);
	array[7].longitude=coordinate_convertToDec(77, 31, 33, false);

	//24° 20' 26'' S - 128° 19' 25'' W
	array[8].latitude=coordinate_convertToDec(24, 20, 26, true);
	array[8].longitude=coordinate_convertToDec(128, 19, 25, true);

	//32° 19' 52'' N - 64° 41' 39'' W
	array[9].latitude=coordinate_convertToDec(32, 19, 52, false);
	array[9].longitude=coordinate_convertToDec(64, 41, 39, true);

	//34° 49' 55'' N - 67° 49' 36'' O
	array[10].latitude=coordinate_convertToDec(34, 49, 55, false);
	array[10].longitude=coordinate_convertToDec(67, 49, 36, false);

	//25° 28' 56'' S - 112° 58' 19'' O
	array[11].latitude=coordinate_convertToDec(25, 28, 56, true);
	array[11].longitude=coordinate_convertToDec(112, 58, 19, false);

	//10° 01' 55'' S - 161° 06' 05'' W
	array[12].latitude=coordinate_convertToDec(10, 01, 55, true);
	array[12].longitude=coordinate_convertToDec(161, 06, 05, true);

	// 32° 40' 26'' N - 117° 14' 20'' W
	array[13].latitude=coordinate_convertToDec(32, 40, 26, false);
	array[13].longitude=coordinate_convertToDec(117, 14, 20, true);

	//03° 50' 38'' S - 32° 25' 17'' W 
	array[14].latitude=coordinate_convertToDec(03, 50, 38, true);
	array[14].longitude=coordinate_convertToDec(32, 25, 17, true);
	//
	array[15].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[15].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[16].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[16].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[17].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[17].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[18].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[18].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[19].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[19].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[20].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[20].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[21].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[21].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[22].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[22].longitude=coordinate_convertToDec(0, 0, 0, false);
	//
	array[23].latitude=coordinate_convertToDec(0, 0, 0, false);
	array[23].longitude=coordinate_convertToDec(0, 0, 0, false);
}

int main()
{
	uint8 i1, i2;
	uint16 iDistance;

	//data arrays
	const uint16 coordinateLength=24;
	coordinate data_coordinate[coordinateLength];

	const uint16 distanceLength=coordinateLength*coordinateLength;
	distance data_distance[distanceLength];

	//init coordinates
	init(data_coordinate);

	//write google earth map
	writeKml(data_coordinate, coordinateLength);

	//calculate rainbow table
	iDistance=0;
	for(i1=0; i1<coordinateLength; i1++)
	{
		for(i2=0; i2<coordinateLength; i2++)
		{
			data_distance[iDistance].point1=i1+1;
			data_distance[iDistance].point2=i2+1;
			
			//do not insert useless data
			if(data_coordinate[i1].latitude!=0.0 && data_coordinate[i1].longitude!=0.0 && 
			   data_coordinate[i2].latitude!=0.0 && data_coordinate[i2].longitude!=0.0)
			{
				//calculate distance
				data_distance[iDistance].distance=geo_distanceWGS84(
					data_coordinate[i1].latitude, data_coordinate[i1].longitude, 
					data_coordinate[i2].latitude, data_coordinate[i2].longitude);
			}
			else
			{
				//invalid distance
				data_distance[iDistance].distance=-1.0;
			}
			iDistance++;
		}
	}

	//sort_quickSort(data_distance, 0, 10);
	
	print_distances(data_distance, iDistance);

	return 0;
}

