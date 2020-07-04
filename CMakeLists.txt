cmake_minimum_required(VERSION 3.15)
project(NewLocker)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME} LockerMain.cpp ./src/Locker.cc)
add_subdirectory(tests)