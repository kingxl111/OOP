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
CMAKE_SOURCE_DIR = "/home/vadim/Рабочий стол/OOP subj/OOP/lab6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build"

# Include any dependencies generated for this target.
include CMakeFiles/lab6_exe.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lab6_exe.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lab6_exe.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lab6_exe.dir/flags.make

CMakeFiles/lab6_exe.dir/src/main.cpp.o: CMakeFiles/lab6_exe.dir/flags.make
CMakeFiles/lab6_exe.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/lab6_exe.dir/src/main.cpp.o: CMakeFiles/lab6_exe.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lab6_exe.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/lab6_exe.dir/src/main.cpp.o -MF CMakeFiles/lab6_exe.dir/src/main.cpp.o.d -o CMakeFiles/lab6_exe.dir/src/main.cpp.o -c "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/src/main.cpp"

CMakeFiles/lab6_exe.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lab6_exe.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/src/main.cpp" > CMakeFiles/lab6_exe.dir/src/main.cpp.i

CMakeFiles/lab6_exe.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lab6_exe.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/src/main.cpp" -o CMakeFiles/lab6_exe.dir/src/main.cpp.s

# Object files for target lab6_exe
lab6_exe_OBJECTS = \
"CMakeFiles/lab6_exe.dir/src/main.cpp.o"

# External object files for target lab6_exe
lab6_exe_EXTERNAL_OBJECTS =

lab6_exe: CMakeFiles/lab6_exe.dir/src/main.cpp.o
lab6_exe: CMakeFiles/lab6_exe.dir/build.make
lab6_exe: liblab6_lib.a
lab6_exe: CMakeFiles/lab6_exe.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lab6_exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lab6_exe.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lab6_exe.dir/build: lab6_exe
.PHONY : CMakeFiles/lab6_exe.dir/build

CMakeFiles/lab6_exe.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lab6_exe.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lab6_exe.dir/clean

CMakeFiles/lab6_exe.dir/depend:
	cd "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/vadim/Рабочий стол/OOP subj/OOP/lab6" "/home/vadim/Рабочий стол/OOP subj/OOP/lab6" "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build" "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build" "/home/vadim/Рабочий стол/OOP subj/OOP/lab6/build/CMakeFiles/lab6_exe.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lab6_exe.dir/depend

