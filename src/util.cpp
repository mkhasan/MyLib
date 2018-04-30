/*
 * util.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: usrc
 */



#include "util.h"

#include <stdio.h>
#include <unistd.h>

#define MAX_DEVICE_STR_LEN 50

using namespace std;

void MY_LIB::TestPrint() {
	printf("Hello Hasan \n");
}


int MY_LIB::GetFirstDeviceNo(const string & prefix, unsigned int minID, unsigned int maxID) {



	char s[256];
	int i;


	if(prefix.length()+sizeof(unsigned int) > MAX_DEVICE_STR_LEN+1)
		return -1;

	for (i = minID; i<maxID; i++)
	{
		sprintf(s, "%s%d", prefix.c_str(), i);

		if( access( s, F_OK ) != -1 )
			break;
	}

	if (i < maxID)
		return i;

	return -1;

}

int MY_LIB::GetFirstDeviceNo(const char * prefix, unsigned int minID, unsigned int maxID) {

	string str(prefix);
	return GetFirstDeviceNo(str, minID, maxID);
}
