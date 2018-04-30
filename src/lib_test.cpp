

#include "util.h"

#include <iostream>

using namespace std;
using namespace MY_LIB;

uint8_t crcCalc(uint8_t const message);
uint8_t crcCalc(uint16_t const message);

//#define

#define POLYNOMIAL 0b11001000;//0xD8  /* 11011 followed by 0's */

int main() {

	TestPrint();

	int ret = GetFirstDeviceNo("/dev/ttyUSB", 0, 20);


	cout << "ret is " << ret << endl;

	uint16_t msg = 0b100000001;

	uint8_t rem = crcCalc(msg);

	printf( "remainder is %x \n", rem);
	return 0;
}




uint8_t
crcCalc(uint8_t const message)
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


uint8_t
crcCalc(uint16_t const message)
{
    uint16_t  remainder;

    const uint16_t polynom = 0xc000;

    /*
     * Initially, the dividend is the remainder.
     */
    remainder = message;

    /*
     * For each bit position in the message....
     */
    for (uint8_t bit = 16; bit > 0; --bit)
    {
        /*
         * If the uppermost bit is a 1...
         */
        if (remainder & 0x8000)
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
    return uint8_t (remainder >> 12);

}   /* crcNaive() */
