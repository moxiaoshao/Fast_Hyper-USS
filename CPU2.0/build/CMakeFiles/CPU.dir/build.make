# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/shizhouran/HyperUSS-master/CPU

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/shizhouran/HyperUSS-master/CPU/build

# Include any dependencies generated for this target.
include CMakeFiles/CPU.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CPU.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CPU.dir/flags.make

CMakeFiles/CPU.dir/main.cpp.o: CMakeFiles/CPU.dir/flags.make
CMakeFiles/CPU.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/shizhouran/HyperUSS-master/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CPU.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CPU.dir/main.cpp.o -c /root/shizhouran/HyperUSS-master/CPU/main.cpp

CMakeFiles/CPU.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CPU.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/shizhouran/HyperUSS-master/CPU/main.cpp > CMakeFiles/CPU.dir/main.cpp.i

CMakeFiles/CPU.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CPU.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/shizhouran/HyperUSS-master/CPU/main.cpp -o CMakeFiles/CPU.dir/main.cpp.s

# Object files for target CPU
CPU_OBJECTS = \
"CMakeFiles/CPU.dir/main.cpp.o"

# External object files for target CPU
CPU_EXTERNAL_OBJECTS =

CPU: CMakeFiles/CPU.dir/main.cpp.o
CPU: CMakeFiles/CPU.dir/build.make
CPU: CMakeFiles/CPU.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/shizhouran/HyperUSS-master/CPU/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CPU"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CPU.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CPU.dir/build: CPU

.PHONY : CMakeFiles/CPU.dir/build

CMakeFiles/CPU.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CPU.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CPU.dir/clean

CMakeFiles/CPU.dir/depend:
	cd /root/shizhouran/HyperUSS-master/CPU/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/shizhouran/HyperUSS-master/CPU /root/shizhouran/HyperUSS-master/CPU /root/shizhouran/HyperUSS-master/CPU/build /root/shizhouran/HyperUSS-master/CPU/build /root/shizhouran/HyperUSS-master/CPU/build/CMakeFiles/CPU.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CPU.dir/depend

