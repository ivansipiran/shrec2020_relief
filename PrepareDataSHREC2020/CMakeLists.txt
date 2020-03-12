cmake_minimum_required( VERSION 2.6 )

project( PrepareDataset )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/src/prepareDataset.cpp)
set(MESHLIB_LIBRARY /home/ivan/Documentos/Software/MeshLib)

include_directories(${MESHLIB_LIBRARY}/Detector/include)
include_directories(${MESHLIB_LIBRARY}/util/include)
link_directories(${MESHLIB_LIBRARY}/bin)

add_executable(PrepareDataset ${PROJECT_SOURCE_FILES})
target_link_libraries(PrepareDataset util MeshLib)