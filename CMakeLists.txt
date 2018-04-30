CMAKE_MINIMUM_REQUIRED (VERSION 2.8)




PROJECT (MY_LIB)

set (TARGET lib_test)

#set (ACE_DIR $ENV{ACE_ROOT})

set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

set(
	LIB_SRC 
	src/util.cpp
	)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb -Wall -fpermissive -Wno-narrowing")

add_library(Util SHARED ${LIB_SRC})

add_executable(${TARGET} src/${TARGET}.cpp)

target_link_libraries(${TARGET} Util)