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
CMAKE_SOURCE_DIR = /home/joagz/Courses/Algorithms/PrattParsing

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/joagz/Courses/Algorithms/PrattParsing/build

# Include any dependencies generated for this target.
include CMakeFiles/expression.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/expression.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/expression.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/expression.dir/flags.make

CMakeFiles/expression.dir/expression/expression.cpp.o: CMakeFiles/expression.dir/flags.make
CMakeFiles/expression.dir/expression/expression.cpp.o: ../expression/expression.cpp
CMakeFiles/expression.dir/expression/expression.cpp.o: CMakeFiles/expression.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/joagz/Courses/Algorithms/PrattParsing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/expression.dir/expression/expression.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/expression.dir/expression/expression.cpp.o -MF CMakeFiles/expression.dir/expression/expression.cpp.o.d -o CMakeFiles/expression.dir/expression/expression.cpp.o -c /home/joagz/Courses/Algorithms/PrattParsing/expression/expression.cpp

CMakeFiles/expression.dir/expression/expression.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/expression.dir/expression/expression.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/joagz/Courses/Algorithms/PrattParsing/expression/expression.cpp > CMakeFiles/expression.dir/expression/expression.cpp.i

CMakeFiles/expression.dir/expression/expression.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/expression.dir/expression/expression.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/joagz/Courses/Algorithms/PrattParsing/expression/expression.cpp -o CMakeFiles/expression.dir/expression/expression.cpp.s

# Object files for target expression
expression_OBJECTS = \
"CMakeFiles/expression.dir/expression/expression.cpp.o"

# External object files for target expression
expression_EXTERNAL_OBJECTS =

../bin/libexpression.a: CMakeFiles/expression.dir/expression/expression.cpp.o
../bin/libexpression.a: CMakeFiles/expression.dir/build.make
../bin/libexpression.a: CMakeFiles/expression.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/joagz/Courses/Algorithms/PrattParsing/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../bin/libexpression.a"
	$(CMAKE_COMMAND) -P CMakeFiles/expression.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/expression.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/expression.dir/build: ../bin/libexpression.a
.PHONY : CMakeFiles/expression.dir/build

CMakeFiles/expression.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/expression.dir/cmake_clean.cmake
.PHONY : CMakeFiles/expression.dir/clean

CMakeFiles/expression.dir/depend:
	cd /home/joagz/Courses/Algorithms/PrattParsing/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/joagz/Courses/Algorithms/PrattParsing /home/joagz/Courses/Algorithms/PrattParsing /home/joagz/Courses/Algorithms/PrattParsing/build /home/joagz/Courses/Algorithms/PrattParsing/build /home/joagz/Courses/Algorithms/PrattParsing/build/CMakeFiles/expression.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/expression.dir/depend

