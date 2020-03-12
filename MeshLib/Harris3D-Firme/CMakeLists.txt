project( Harris3D_demo )

CMAKE_MINIMUM_REQUIRED(VERSION 2.4.5)

	set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
	set(PROJECT_SOURCE_FILES ${PROJECT_SOURCE_DIR}/main.cpp)

	include_directories( ${PROJECT_LIBRARY}/Detector/include )
	include_directories( ${PROJECT_LIBRARY}/util/include )

	#IMPORTANTE: Configurar todos estas rutas de acuerdo con tu sistema
	include_directories( C:/Users/Admin/Documents/Software/CGAL-release/include ) #CGAL include
	include_directories( C:/Users/Admin/Documents/Software/boost-release/include/boost-1_60 ) #Boost include
	include_directories( C:/Users/Admin/Documents/Software/CGAL-4.7/build/include ) #Directory where to find compiler_config.h
	include_directories( C:/Users/Admin/Documents/Software/eigen-eigen-07105f7124f9 ) #Eigen include
	link_directories (C:/Users/Admin/Documents/Software/boost-release/lib)


	add_executable(Harris3D_demo ${PROJECT_SOURCE_FILES})

	target_link_libraries(Harris3D_demo ${PROJECT_LIBRARY}/build/Detector/Release/Harris3D.lib )
	target_link_libraries(Harris3D_demo ${PROJECT_LIBRARY}/build/util/Release/Util.lib )

	#IMPORTANTE: Configurar todos estas rutas de acuerdo con tu sistema
	target_link_libraries ( Harris3D_demo C:/Users/Admin/Documents/Software/CGAL-release/build/lib/Release/libCGAL-vc120-mt-4.7.lib )

    set_target_properties (Harris3D_demo PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
    set_target_properties (Harris3D_demo PROPERTIES LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_CURRENT_SOURCE_DIR}/../bin )
