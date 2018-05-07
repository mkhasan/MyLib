

#include "util.h"

#include <iostream>

using namespace std;
using namespace MY_LIB;


//#define



int main() {

	TestPrint();

	int ret = GetFirstDeviceNo("/dev/ttyUSB", 0, 20);


	cout << "ret is " << ret << endl;

	uint32_t msg = 0b100100;

	//uint8_t rem = crcCalc(msg, 6, 0b1101);
	//uint8_t rem = crcCalc(0b11100110, 8, 0b11001);

	//uint8_t rem = crcCalc(0b1111, 4, 0b1011);
	uint8_t rem = crcCalc(uint32_t(1), 8, 0x19 );

	//printf( "order is %x \n", GetDegree(0b11001));
	printf( "remainder is %x \n", rem);
	return 0;
}




