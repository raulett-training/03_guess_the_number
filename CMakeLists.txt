cmake_minimum_required(VERSION 3.25)
project(03_guess_the_number)

set(CMAKE_CXX_STANDARD 17)

add_executable(03_guess_the_number Src/main.cpp Src/RecordTable.cpp Src/RecordTable.h)
