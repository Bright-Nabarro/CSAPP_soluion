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
CMAKE_SOURCE_DIR = /mnt/d/cpptest/c/computer_systems/homework9/17_18_20

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/cpptest/c/computer_systems/homework9/17_18_20

# Include any dependencies generated for this target.
include CMakeFiles/app.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/app.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/app.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/app.dir/flags.make

CMakeFiles/app.dir/mem_stm.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/mem_stm.c.o: mem_stm.c
CMakeFiles/app.dir/mem_stm.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/cpptest/c/computer_systems/homework9/17_18_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/app.dir/mem_stm.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/mem_stm.c.o -MF CMakeFiles/app.dir/mem_stm.c.o.d -o CMakeFiles/app.dir/mem_stm.c.o -c /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mem_stm.c

CMakeFiles/app.dir/mem_stm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/mem_stm.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mem_stm.c > CMakeFiles/app.dir/mem_stm.c.i

CMakeFiles/app.dir/mem_stm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/mem_stm.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mem_stm.c -o CMakeFiles/app.dir/mem_stm.c.s

CMakeFiles/app.dir/mm.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/mm.c.o: mm.c
CMakeFiles/app.dir/mm.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/cpptest/c/computer_systems/homework9/17_18_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/app.dir/mm.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/mm.c.o -MF CMakeFiles/app.dir/mm.c.o.d -o CMakeFiles/app.dir/mm.c.o -c /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mm.c

CMakeFiles/app.dir/mm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/mm.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mm.c > CMakeFiles/app.dir/mm.c.i

CMakeFiles/app.dir/mm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/mm.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/mm.c -o CMakeFiles/app.dir/mm.c.s

CMakeFiles/app.dir/test.c.o: CMakeFiles/app.dir/flags.make
CMakeFiles/app.dir/test.c.o: test.c
CMakeFiles/app.dir/test.c.o: CMakeFiles/app.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/d/cpptest/c/computer_systems/homework9/17_18_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/app.dir/test.c.o"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/app.dir/test.c.o -MF CMakeFiles/app.dir/test.c.o.d -o CMakeFiles/app.dir/test.c.o -c /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/test.c

CMakeFiles/app.dir/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/app.dir/test.c.i"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/test.c > CMakeFiles/app.dir/test.c.i

CMakeFiles/app.dir/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/app.dir/test.c.s"
	/usr/sbin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/test.c -o CMakeFiles/app.dir/test.c.s

# Object files for target app
app_OBJECTS = \
"CMakeFiles/app.dir/mem_stm.c.o" \
"CMakeFiles/app.dir/mm.c.o" \
"CMakeFiles/app.dir/test.c.o"

# External object files for target app
app_EXTERNAL_OBJECTS =

app: CMakeFiles/app.dir/mem_stm.c.o
app: CMakeFiles/app.dir/mm.c.o
app: CMakeFiles/app.dir/test.c.o
app: CMakeFiles/app.dir/build.make
app: CMakeFiles/app.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/d/cpptest/c/computer_systems/homework9/17_18_20/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable app"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/app.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/app.dir/build: app
.PHONY : CMakeFiles/app.dir/build

CMakeFiles/app.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/app.dir/cmake_clean.cmake
.PHONY : CMakeFiles/app.dir/clean

CMakeFiles/app.dir/depend:
	cd /mnt/d/cpptest/c/computer_systems/homework9/17_18_20 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/cpptest/c/computer_systems/homework9/17_18_20 /mnt/d/cpptest/c/computer_systems/homework9/17_18_20 /mnt/d/cpptest/c/computer_systems/homework9/17_18_20 /mnt/d/cpptest/c/computer_systems/homework9/17_18_20 /mnt/d/cpptest/c/computer_systems/homework9/17_18_20/CMakeFiles/app.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/app.dir/depend

