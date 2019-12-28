project (rnet)

set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -Werror -pedantic -pthread")

if (UNIX)
    set(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(rnet src/rnet.h src/rnet.cpp)
