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
CMAKE_SOURCE_DIR = "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp"

# Include any dependencies generated for this target.
include lib/CMakeFiles/std_function_lib.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/std_function_lib.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/std_function_lib.dir/flags.make

lib/CMakeFiles/std_function_lib.dir/std_function.cpp.o: lib/CMakeFiles/std_function_lib.dir/flags.make
lib/CMakeFiles/std_function_lib.dir/std_function.cpp.o: ../lib/std_function.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/std_function_lib.dir/std_function.cpp.o"
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/std_function_lib.dir/std_function.cpp.o -c "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/lib/std_function.cpp"

lib/CMakeFiles/std_function_lib.dir/std_function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/std_function_lib.dir/std_function.cpp.i"
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/lib/std_function.cpp" > CMakeFiles/std_function_lib.dir/std_function.cpp.i

lib/CMakeFiles/std_function_lib.dir/std_function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/std_function_lib.dir/std_function.cpp.s"
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/lib/std_function.cpp" -o CMakeFiles/std_function_lib.dir/std_function.cpp.s

# Object files for target std_function_lib
std_function_lib_OBJECTS = \
"CMakeFiles/std_function_lib.dir/std_function.cpp.o"

# External object files for target std_function_lib
std_function_lib_EXTERNAL_OBJECTS =

lib/libstd_function_lib.a: lib/CMakeFiles/std_function_lib.dir/std_function.cpp.o
lib/libstd_function_lib.a: lib/CMakeFiles/std_function_lib.dir/build.make
lib/libstd_function_lib.a: lib/CMakeFiles/std_function_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libstd_function_lib.a"
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && $(CMAKE_COMMAND) -P CMakeFiles/std_function_lib.dir/cmake_clean_target.cmake
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/std_function_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/std_function_lib.dir/build: lib/libstd_function_lib.a

.PHONY : lib/CMakeFiles/std_function_lib.dir/build

lib/CMakeFiles/std_function_lib.dir/clean:
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" && $(CMAKE_COMMAND) -P CMakeFiles/std_function_lib.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/std_function_lib.dir/clean

lib/CMakeFiles/std_function_lib.dir/depend:
	cd "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function" "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/lib" "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp" "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib" "/mnt/e/_Vladik/6-Mail_Technopark/3-ML-developer/o_2semester/2-multithreaded programming in C_С_plus/1-lectures_HW/n0_code/hw1/repo/std_function/tmp/lib/CMakeFiles/std_function_lib.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : lib/CMakeFiles/std_function_lib.dir/depend
