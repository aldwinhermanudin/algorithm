# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build

# Include any dependencies generated for this target.
include CMakeFiles/sanityCheck.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sanityCheck.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sanityCheck.dir/flags.make

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o: CMakeFiles/sanityCheck.dir/flags.make
CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o: ../src/sanity_check.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o -c /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/src/sanity_check.cpp

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/src/sanity_check.cpp > CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.i

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/src/sanity_check.cpp -o CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.s

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.requires:

.PHONY : CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.requires

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.provides: CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.requires
	$(MAKE) -f CMakeFiles/sanityCheck.dir/build.make CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.provides.build
.PHONY : CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.provides

CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.provides.build: CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o


# Object files for target sanityCheck
sanityCheck_OBJECTS = \
"CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o"

# External object files for target sanityCheck
sanityCheck_EXTERNAL_OBJECTS =

sanityCheck: CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o
sanityCheck: CMakeFiles/sanityCheck.dir/build.make
sanityCheck: CMakeFiles/sanityCheck.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sanityCheck"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sanityCheck.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sanityCheck.dir/build: sanityCheck

.PHONY : CMakeFiles/sanityCheck.dir/build

CMakeFiles/sanityCheck.dir/requires: CMakeFiles/sanityCheck.dir/src/sanity_check.cpp.o.requires

.PHONY : CMakeFiles/sanityCheck.dir/requires

CMakeFiles/sanityCheck.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sanityCheck.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sanityCheck.dir/clean

CMakeFiles/sanityCheck.dir/depend:
	cd /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build /home/aldwinakbar/Dropbox/Projects/campus/personal/algorithm/misc/build/CMakeFiles/sanityCheck.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sanityCheck.dir/depend

