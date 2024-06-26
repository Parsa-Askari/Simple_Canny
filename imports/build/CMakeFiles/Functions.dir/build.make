# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = "/home/parsa/Codes/opencv projects/c++/imports"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/parsa/Codes/opencv projects/c++/imports/build"

# Include any dependencies generated for this target.
include CMakeFiles/Functions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Functions.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Functions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Functions.dir/flags.make

CMakeFiles/Functions.dir/functions.cpp.o: CMakeFiles/Functions.dir/flags.make
CMakeFiles/Functions.dir/functions.cpp.o: ../functions.cpp
CMakeFiles/Functions.dir/functions.cpp.o: CMakeFiles/Functions.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/parsa/Codes/opencv projects/c++/imports/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Functions.dir/functions.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Functions.dir/functions.cpp.o -MF CMakeFiles/Functions.dir/functions.cpp.o.d -o CMakeFiles/Functions.dir/functions.cpp.o -c "/home/parsa/Codes/opencv projects/c++/imports/functions.cpp"

CMakeFiles/Functions.dir/functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Functions.dir/functions.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/parsa/Codes/opencv projects/c++/imports/functions.cpp" > CMakeFiles/Functions.dir/functions.cpp.i

CMakeFiles/Functions.dir/functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Functions.dir/functions.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/parsa/Codes/opencv projects/c++/imports/functions.cpp" -o CMakeFiles/Functions.dir/functions.cpp.s

# Object files for target Functions
Functions_OBJECTS = \
"CMakeFiles/Functions.dir/functions.cpp.o"

# External object files for target Functions
Functions_EXTERNAL_OBJECTS =

libFunctions.a: CMakeFiles/Functions.dir/functions.cpp.o
libFunctions.a: CMakeFiles/Functions.dir/build.make
libFunctions.a: CMakeFiles/Functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/parsa/Codes/opencv projects/c++/imports/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libFunctions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Functions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Functions.dir/build: libFunctions.a
.PHONY : CMakeFiles/Functions.dir/build

CMakeFiles/Functions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Functions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Functions.dir/clean

CMakeFiles/Functions.dir/depend:
	cd "/home/parsa/Codes/opencv projects/c++/imports/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/parsa/Codes/opencv projects/c++/imports" "/home/parsa/Codes/opencv projects/c++/imports" "/home/parsa/Codes/opencv projects/c++/imports/build" "/home/parsa/Codes/opencv projects/c++/imports/build" "/home/parsa/Codes/opencv projects/c++/imports/build/CMakeFiles/Functions.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Functions.dir/depend

