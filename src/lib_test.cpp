

#include "util.h"

#include <iostream>

using namespace std;
using namespace MY_LIB;

int main() {

	TestPrint();

	int ret = GetFirstDeviceNo("/dev/ttyUSB", 0, 20);


	cout << "ret is " << ret << endl;
	return 0;
}
