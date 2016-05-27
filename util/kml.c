#include <stdio.h>

#include "../system_types.h"
#include "../system_structures.h"
#include "kml.h"

void writeKml(coordinate* array, uint8 length)
{
	uint8 i;
	const char* header = "﻿<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<kml xmlns=\"http://www.opengis.net/kml/2.2\" xmlns:gx=\"http://www.google.com/kml/ext/2.2\" xmlns:kml=\"http://www.opengis.net/kml/2.2\" xmlns:atom=\"http://www.w3.org/2005/Atom\">\n<Document>\n	<Style id=\"s_pushpin_hl\">\n		<IconStyle>\n			<scale>5.0</scale>\n			<Icon>\n				<href>http://maps.google.com/mapfiles/kml/paddle/red-blank.png</href>\n			</Icon>\n			<hotSpot x=\"20\" y=\"2\" xunits=\"pixels\" yunits=\"pixels\"/>\n		</IconStyle>\n	</Style>\n	<Style id=\"s_pushpin\">\n		<IconStyle>\n			<scale>5.0</scale>\n			<Icon>\n				<href>http://maps.google.com/mapfiles/kml/paddle/red-blank.png</href>\n			</Icon>\n			<hotSpot x=\"20\" y=\"2\" xunits=\"pixels\" yunits=\"pixels\"/>\n		</IconStyle>\n	</Style>\n	<StyleMap id=\"m_pushpin\">\n		<Pair>\n			<key>normal</key>\n			<styleUrl>#s_pushpin</styleUrl>\n		</Pair>\n		<Pair>\n			<key>highlight</key>\n			<styleUrl>#s_pushpin_hl</styleUrl>\n		</Pair>\n	</StyleMap>";
	const char* footer = "\t</Document>\n</kml>";

	FILE *f = fopen("map.kml", "w");
	if(f == NULL)
	{
		printf("Error opening file!\n");
		return;
	}

	fprintf(f, "%s\n", header);
	for(i=0; i<length; i++)
	{
		if(array[i].longitude!=0.0 && array[i].latitude!=0.0)
		{
			fprintf(f, "<Placemark id=\"%d\">\n	<name>%d</name>\n	<styleUrl>#m_pushpin</styleUrl>\n	<LookAt>\n			<altitude>15000000</altitude>\n			<heading>0</heading>\n			<tilt>0</tilt>\n			<longitude>%Lf</longitude>\n			<latitude>%Lf</latitude>\n			<gx:altitudeMode>absolute</gx:altitudeMode>\n		</LookAt>\n	<Point>\n		<coordinates>%Lf,%Lf,0</coordinates>\n	</Point>\n</Placemark>\n", i+1, i+1, array[i].longitude, array[i].latitude, array[i].longitude, array[i].latitude);
		}
	}
	fprintf(f, "%s\n", footer);
	fclose(f);
}
