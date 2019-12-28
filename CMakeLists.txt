project (rnet)

if (UNIX)
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -pthread")
endif (UNIX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(rnet src/rnet.h src/rnet.cpp)
