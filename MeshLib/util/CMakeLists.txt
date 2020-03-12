cmake_minimum_required(VERSION 2.8)

project(Util)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_definitions( -DUTIL_LIBRARY )

add_library(Util SHARED src/Properties.cpp src/util.cpp)

set_target_properties (Util PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
set_target_properties (Util PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
