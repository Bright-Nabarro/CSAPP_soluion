# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /mnt/d/cpptest/c/computer_systems/homework10/8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cpptest/c/computer_systems/homework10/8

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/fstatcheck.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/fstatcheck.c.o: fstatcheck.c
CMakeFiles/app.dir/fstatcheck.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/cpptest/c/computer_systems/homework10/8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app.dir/fstatcheck.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/fstatcheck.c.o -MF CMakeFiles/app.dir/fstatcheck.c.o.d -o CMakeFiles/app.dir/fstatcheck.c.o -c /mnt/d/cpptest/c/computer_systems/homework10/8/fstatcheck.c

CMakeFiles/app.dir/fstatcheck.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/fstatcheck.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/cpptest/c/computer_systems/homework10/8/fstatcheck.c > CMakeFiles/app.dir/fstatcheck.c.i

CMakeFiles/app.dir/fstatcheck.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/fstatcheck.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/cpptest/c/computer_systems/homework10/8/fstatcheck.c -o CMakeFiles/app.dir/fstatcheck.c.s

CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o: /mnt/d/cpptest/c/computer_systems/csapp.c
CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/cpptest/c/computer_systems/homework10/8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o -MF CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o.d -o CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o -c /mnt/d/cpptest/c/computer_systems/csapp.c

CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/cpptest/c/computer_systems/csapp.c > CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.i

CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/cpptest/c/computer_systems/csapp.c -o CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/fstatcheck.c.o" \
"CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/fstatcheck.c.o
app: CMakeFiles/app.dir/mnt/d/cpptest/c/computer_systems/csapp.c.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/cpptest/c/computer_systems/homework10/8/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /mnt/d/cpptest/c/computer_systems/homework10/8 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cpptest/c/computer_systems/homework10/8 /mnt/d/cpptest/c/computer_systems/homework10/8 /mnt/d/cpptest/c/computer_systems/homework10/8 /mnt/d/cpptest/c/computer_systems/homework10/8 /mnt/d/cpptest/c/computer_systems/homework10/8/CMakeFiles/app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/app.dir/depend
