cmake_minimum_required(VERSION 3.5.1)
project(test_server)

set(CMAKE_CXX_STANDARD 14)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED)

add_definitions(-DBOOST_ERROR_CODE_HEADER_ONLY)
add_definitions(-DBOOST_SYSTEM_NO_DEPRECATED)

add_executable(test_server main.cpp server.cpp session.cpp)
target_include_directories(test_server PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(test_server PUBLIC ${Boost_LIBRARIES})
target_link_libraries(test_server PUBLIC ${CMAKE_THREAD_LIBS_INIT})
