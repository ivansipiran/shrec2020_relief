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
CMAKE_SOURCE_DIR = /home/ivan/Documentos/Software/PrepareDataSHREC2020

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/Documentos/Software/PrepareDataSHREC2020/build

# Include any dependencies generated for this target.
include CMakeFiles/PrepareDataset.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PrepareDataset.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PrepareDataset.dir/flags.make

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o: CMakeFiles/PrepareDataset.dir/flags.make
CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o: ../src/prepareDataset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/Documentos/Software/PrepareDataSHREC2020/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o -c /home/ivan/Documentos/Software/PrepareDataSHREC2020/src/prepareDataset.cpp

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/Documentos/Software/PrepareDataSHREC2020/src/prepareDataset.cpp > CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.i

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/Documentos/Software/PrepareDataSHREC2020/src/prepareDataset.cpp -o CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.s

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.requires:

.PHONY : CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.requires

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.provides: CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.requires
	$(MAKE) -f CMakeFiles/PrepareDataset.dir/build.make CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.provides.build
.PHONY : CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.provides

CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.provides.build: CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o


# Object files for target PrepareDataset
PrepareDataset_OBJECTS = \
"CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o"

# External object files for target PrepareDataset
PrepareDataset_EXTERNAL_OBJECTS =

PrepareDataset: CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o
PrepareDataset: CMakeFiles/PrepareDataset.dir/build.make
PrepareDataset: CMakeFiles/PrepareDataset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/Documentos/Software/PrepareDataSHREC2020/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PrepareDataset"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PrepareDataset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PrepareDataset.dir/build: PrepareDataset

.PHONY : CMakeFiles/PrepareDataset.dir/build

CMakeFiles/PrepareDataset.dir/requires: CMakeFiles/PrepareDataset.dir/src/prepareDataset.cpp.o.requires

.PHONY : CMakeFiles/PrepareDataset.dir/requires

CMakeFiles/PrepareDataset.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PrepareDataset.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PrepareDataset.dir/clean

CMakeFiles/PrepareDataset.dir/depend:
	cd /home/ivan/Documentos/Software/PrepareDataSHREC2020/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/Documentos/Software/PrepareDataSHREC2020 /home/ivan/Documentos/Software/PrepareDataSHREC2020 /home/ivan/Documentos/Software/PrepareDataSHREC2020/build /home/ivan/Documentos/Software/PrepareDataSHREC2020/build /home/ivan/Documentos/Software/PrepareDataSHREC2020/build/CMakeFiles/PrepareDataset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PrepareDataset.dir/depend
