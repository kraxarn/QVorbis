cmake_minimum_required(VERSION 3.5)

#
# QVorbis Demo
# Building:
# mkdir build && cd build && cmake .. && make
#

project(qvorbis_demo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Core Multimedia REQUIRED)

add_executable(qvorbis_demo demo.cpp QVorbis.cpp)

target_link_libraries(qvorbis_demo PRIVATE
		Qt5::Core
		Qt5::Multimedia)