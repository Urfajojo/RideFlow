# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
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
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/Owner/CLionProjects/RideFlow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/RideFlow.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/RideFlow.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/RideFlow.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/RideFlow.dir/flags.make

CMakeFiles/RideFlow.dir/Rideflow.cpp.o: CMakeFiles/RideFlow.dir/flags.make
CMakeFiles/RideFlow.dir/Rideflow.cpp.o: /mnt/c/Users/Owner/CLionProjects/RideFlow/Rideflow.cpp
CMakeFiles/RideFlow.dir/Rideflow.cpp.o: CMakeFiles/RideFlow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/RideFlow.dir/Rideflow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RideFlow.dir/Rideflow.cpp.o -MF CMakeFiles/RideFlow.dir/Rideflow.cpp.o.d -o CMakeFiles/RideFlow.dir/Rideflow.cpp.o -c /mnt/c/Users/Owner/CLionProjects/RideFlow/Rideflow.cpp

CMakeFiles/RideFlow.dir/Rideflow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RideFlow.dir/Rideflow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Owner/CLionProjects/RideFlow/Rideflow.cpp > CMakeFiles/RideFlow.dir/Rideflow.cpp.i

CMakeFiles/RideFlow.dir/Rideflow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RideFlow.dir/Rideflow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Owner/CLionProjects/RideFlow/Rideflow.cpp -o CMakeFiles/RideFlow.dir/Rideflow.cpp.s

CMakeFiles/RideFlow.dir/opensocket.cpp.o: CMakeFiles/RideFlow.dir/flags.make
CMakeFiles/RideFlow.dir/opensocket.cpp.o: /mnt/c/Users/Owner/CLionProjects/RideFlow/opensocket.cpp
CMakeFiles/RideFlow.dir/opensocket.cpp.o: CMakeFiles/RideFlow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/RideFlow.dir/opensocket.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RideFlow.dir/opensocket.cpp.o -MF CMakeFiles/RideFlow.dir/opensocket.cpp.o.d -o CMakeFiles/RideFlow.dir/opensocket.cpp.o -c /mnt/c/Users/Owner/CLionProjects/RideFlow/opensocket.cpp

CMakeFiles/RideFlow.dir/opensocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RideFlow.dir/opensocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Owner/CLionProjects/RideFlow/opensocket.cpp > CMakeFiles/RideFlow.dir/opensocket.cpp.i

CMakeFiles/RideFlow.dir/opensocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RideFlow.dir/opensocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Owner/CLionProjects/RideFlow/opensocket.cpp -o CMakeFiles/RideFlow.dir/opensocket.cpp.s

CMakeFiles/RideFlow.dir/readcan.cpp.o: CMakeFiles/RideFlow.dir/flags.make
CMakeFiles/RideFlow.dir/readcan.cpp.o: /mnt/c/Users/Owner/CLionProjects/RideFlow/readcan.cpp
CMakeFiles/RideFlow.dir/readcan.cpp.o: CMakeFiles/RideFlow.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/RideFlow.dir/readcan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/RideFlow.dir/readcan.cpp.o -MF CMakeFiles/RideFlow.dir/readcan.cpp.o.d -o CMakeFiles/RideFlow.dir/readcan.cpp.o -c /mnt/c/Users/Owner/CLionProjects/RideFlow/readcan.cpp

CMakeFiles/RideFlow.dir/readcan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/RideFlow.dir/readcan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/Owner/CLionProjects/RideFlow/readcan.cpp > CMakeFiles/RideFlow.dir/readcan.cpp.i

CMakeFiles/RideFlow.dir/readcan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/RideFlow.dir/readcan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/Owner/CLionProjects/RideFlow/readcan.cpp -o CMakeFiles/RideFlow.dir/readcan.cpp.s

# Object files for target RideFlow
RideFlow_OBJECTS = \
"CMakeFiles/RideFlow.dir/Rideflow.cpp.o" \
"CMakeFiles/RideFlow.dir/opensocket.cpp.o" \
"CMakeFiles/RideFlow.dir/readcan.cpp.o"

# External object files for target RideFlow
RideFlow_EXTERNAL_OBJECTS =

RideFlow: CMakeFiles/RideFlow.dir/Rideflow.cpp.o
RideFlow: CMakeFiles/RideFlow.dir/opensocket.cpp.o
RideFlow: CMakeFiles/RideFlow.dir/readcan.cpp.o
RideFlow: CMakeFiles/RideFlow.dir/build.make
RideFlow: CMakeFiles/RideFlow.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable RideFlow"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/RideFlow.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/RideFlow.dir/build: RideFlow
.PHONY : CMakeFiles/RideFlow.dir/build

CMakeFiles/RideFlow.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/RideFlow.dir/cmake_clean.cmake
.PHONY : CMakeFiles/RideFlow.dir/clean

CMakeFiles/RideFlow.dir/depend:
	cd /mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/Owner/CLionProjects/RideFlow /mnt/c/Users/Owner/CLionProjects/RideFlow /mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug /mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug /mnt/c/Users/Owner/CLionProjects/RideFlow/cmake-build-debug/CMakeFiles/RideFlow.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/RideFlow.dir/depend

