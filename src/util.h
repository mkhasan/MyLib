/*
 * util.h
 *
 *  Created on: Apr 30, 2018
 *      Author: usrc
 */

#ifndef SRC_UTIL_H_
#define SRC_UTIL_H_

#include <string>

namespace MY_LIB {


	void TestPrint();

	int GetFirstDeviceNo(const std::string & prefix, unsigned int minID, unsigned int maxID);
	int GetFirstDeviceNo(const char * prefix, unsigned int minID, unsigned int maxID);

}


#endif /* SRC_UTIL_H_ */
