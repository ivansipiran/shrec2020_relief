cmake_minimum_required (VERSION 2.6)

project ( MeshLib )

#IMPORTANTE: Configurar variable PROJECT_LIBRARY al directorio raiz del proyecto completo (no usar \, mejor usar /)
set(PROJECT_LIBRARY /home/isipiran/Software/shrec2020_relief/MeshLib )

set(CMAKE_BUILD_TYPE Release)

add_subdirectory(util)
add_subdirectory(Detector)

add_dependencies(MeshLib Util)

