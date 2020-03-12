cmake_minimum_required(VERSION 2.8)

project (MeshLib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../util/include)

add_definitions( -DMESH_LIBRARY )

add_library(MeshLib SHARED src/Vertex.cpp src src/Face.cpp src/Mesh.cpp)

#IMPORTANTE: Configurar estos directorios de acuerdo al sistema
target_link_libraries ( MeshLib ${PROJECT_LIBRARY}/bin/libUtil.so)

set_target_properties (MeshLib PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
set_target_properties (MeshLib PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
