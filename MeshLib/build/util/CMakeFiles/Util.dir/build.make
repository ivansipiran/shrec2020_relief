# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ivan/Documentos/Software/MeshLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Documentos/Software/MeshLib/build

# Include any dependencies generated for this target.
include util/CMakeFiles/Util.dir/depend.make

# Include the progress variables for this target.
include util/CMakeFiles/Util.dir/progress.make

# Include the compile flags for this target's objects.
include util/CMakeFiles/Util.dir/flags.make

util/CMakeFiles/Util.dir/src/Properties.cpp.o: util/CMakeFiles/Util.dir/flags.make
util/CMakeFiles/Util.dir/src/Properties.cpp.o: ../util/src/Properties.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/Documentos/Software/MeshLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object util/CMakeFiles/Util.dir/src/Properties.cpp.o"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Util.dir/src/Properties.cpp.o -c /home/ivan/Documentos/Software/MeshLib/util/src/Properties.cpp

util/CMakeFiles/Util.dir/src/Properties.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Util.dir/src/Properties.cpp.i"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Documentos/Software/MeshLib/util/src/Properties.cpp > CMakeFiles/Util.dir/src/Properties.cpp.i

util/CMakeFiles/Util.dir/src/Properties.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Util.dir/src/Properties.cpp.s"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Documentos/Software/MeshLib/util/src/Properties.cpp -o CMakeFiles/Util.dir/src/Properties.cpp.s

util/CMakeFiles/Util.dir/src/Properties.cpp.o.requires:

.PHONY : util/CMakeFiles/Util.dir/src/Properties.cpp.o.requires

util/CMakeFiles/Util.dir/src/Properties.cpp.o.provides: util/CMakeFiles/Util.dir/src/Properties.cpp.o.requires
	$(MAKE) -f util/CMakeFiles/Util.dir/build.make util/CMakeFiles/Util.dir/src/Properties.cpp.o.provides.build
.PHONY : util/CMakeFiles/Util.dir/src/Properties.cpp.o.provides

util/CMakeFiles/Util.dir/src/Properties.cpp.o.provides.build: util/CMakeFiles/Util.dir/src/Properties.cpp.o


util/CMakeFiles/Util.dir/src/util.cpp.o: util/CMakeFiles/Util.dir/flags.make
util/CMakeFiles/Util.dir/src/util.cpp.o: ../util/src/util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/Documentos/Software/MeshLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object util/CMakeFiles/Util.dir/src/util.cpp.o"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Util.dir/src/util.cpp.o -c /home/ivan/Documentos/Software/MeshLib/util/src/util.cpp

util/CMakeFiles/Util.dir/src/util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Util.dir/src/util.cpp.i"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Documentos/Software/MeshLib/util/src/util.cpp > CMakeFiles/Util.dir/src/util.cpp.i

util/CMakeFiles/Util.dir/src/util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Util.dir/src/util.cpp.s"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Documentos/Software/MeshLib/util/src/util.cpp -o CMakeFiles/Util.dir/src/util.cpp.s

util/CMakeFiles/Util.dir/src/util.cpp.o.requires:

.PHONY : util/CMakeFiles/Util.dir/src/util.cpp.o.requires

util/CMakeFiles/Util.dir/src/util.cpp.o.provides: util/CMakeFiles/Util.dir/src/util.cpp.o.requires
	$(MAKE) -f util/CMakeFiles/Util.dir/build.make util/CMakeFiles/Util.dir/src/util.cpp.o.provides.build
.PHONY : util/CMakeFiles/Util.dir/src/util.cpp.o.provides

util/CMakeFiles/Util.dir/src/util.cpp.o.provides.build: util/CMakeFiles/Util.dir/src/util.cpp.o


# Object files for target Util
Util_OBJECTS = \
"CMakeFiles/Util.dir/src/Properties.cpp.o" \
"CMakeFiles/Util.dir/src/util.cpp.o"

# External object files for target Util
Util_EXTERNAL_OBJECTS =

../bin/libUtil.so: util/CMakeFiles/Util.dir/src/Properties.cpp.o
../bin/libUtil.so: util/CMakeFiles/Util.dir/src/util.cpp.o
../bin/libUtil.so: util/CMakeFiles/Util.dir/build.make
../bin/libUtil.so: util/CMakeFiles/Util.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/Documentos/Software/MeshLib/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library ../../bin/libUtil.so"
	cd /home/ivan/Documentos/Software/MeshLib/build/util && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Util.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
util/CMakeFiles/Util.dir/build: ../bin/libUtil.so

.PHONY : util/CMakeFiles/Util.dir/build

util/CMakeFiles/Util.dir/requires: util/CMakeFiles/Util.dir/src/Properties.cpp.o.requires
util/CMakeFiles/Util.dir/requires: util/CMakeFiles/Util.dir/src/util.cpp.o.requires

.PHONY : util/CMakeFiles/Util.dir/requires

util/CMakeFiles/Util.dir/clean:
	cd /home/ivan/Documentos/Software/MeshLib/build/util && $(CMAKE_COMMAND) -P CMakeFiles/Util.dir/cmake_clean.cmake
.PHONY : util/CMakeFiles/Util.dir/clean

util/CMakeFiles/Util.dir/depend:
	cd /home/ivan/Documentos/Software/MeshLib/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Documentos/Software/MeshLib /home/ivan/Documentos/Software/MeshLib/util /home/ivan/Documentos/Software/MeshLib/build /home/ivan/Documentos/Software/MeshLib/build/util /home/ivan/Documentos/Software/MeshLib/build/util/CMakeFiles/Util.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : util/CMakeFiles/Util.dir/depend
