/*
 * util.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: usrc
 */



#include "util.h"

#include <stdio.h>
#include <unistd.h>
#include <assert.h>

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

uint8_t MY_LIB::crcCalc(uint8_t const message)
{
    uint8_t  remainder;


    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (uint8_t bit = 8; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & 0x80)
        {
            /*
             * XOR the previous remainder with the divisor.
             */


            remainder ^= POLYNOMIAL;
        }


        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */
    return (remainder >> 4);;

}   /* crcNaive() */


uint8_t MY_LIB::crcCalc(uint32_t const message, int const msgLen, uint32_t polynom)
{
    uint32_t  remainder;

    int deg = GetDegree(polynom);
    assert(deg >= 0 && deg <= msgLen);
    polynom <<= (msgLen-deg-1);	//0b110100;

    const uint32_t mask = 1 << (msgLen-1);
    //const int maxIt = msgLen;

    printf("poly is %x \n", polynom);
    /*
     * Initially, the dividend is the remainder.
     *
     *
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (uint8_t bit = msgLen; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & mask)
        {
            /*
             * XOR the previous remainder with the divisor.
             */
            remainder ^= polynom;
        }


        /*
         * Shift the next bit of the message into the remainder.
         */
        remainder = (remainder << 1);
        printf("it %d: remainder is %x \n", msgLen-bit, remainder);
    }

    /*
     * Return only the relevant bits of the remainder as CRC.
     */

    const uint32_t remMask = ((1<<deg) - 1);
    return uint8_t ((remainder >> (msgLen-deg)) & remMask);

}   /* crcNaive() */

int MY_LIB::GetDegree(uint32_t polynom) {
	int degree = -1;
	while(polynom) {
		polynom >>= 1;
		degree ++;
	}

	return degree;
}
