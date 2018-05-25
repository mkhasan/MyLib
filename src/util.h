/*
 * util.h
 *
 *  Created on: Apr 30, 2018
 *      Author: usrc
 */

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>

#define POLYNOMIAL 0b11001000;//0xD8  /* 11011 followed by 0's */

namespace MY_LIB {


	void TestPrint();

	int GetFirstDeviceNo(const std::string & prefix, unsigned int minID, unsigned int maxID);
	int GetFirstDeviceNo(const char * prefix, unsigned int minID, unsigned int maxID);

	uint8_t crcCalc(uint8_t const message);
	uint8_t crcCalc(uint32_t const message);
	uint8_t crcCalc(uint32_t const message, int const msgLen, uint32_t polynom);

	int GetDegree(uint32_t polynom);



}


#endif /* SRC_UTIL_H_ */
