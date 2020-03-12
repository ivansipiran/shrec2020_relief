cmake_minimum_required(VERSION 2.8)

project(AdaptiveClustering)
set(CMAKE_BUILD_TYPE Release)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_definitions( /DADAPTIVE_LIBRARY )
add_definitions( /D_SECURE_SCL=0)

add_library(AdaptiveClustering SHARED src/adaptiveClustering.cpp src/cluster.cpp)

set_target_properties (AdaptiveClustering PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
set_target_properties (AdaptiveClustering PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
