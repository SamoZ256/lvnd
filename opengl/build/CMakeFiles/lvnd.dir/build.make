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
CMAKE_SOURCE_DIR = /home/samuliak/Documents/lvnd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/samuliak/Documents/lvnd/opengl/build

# Include any dependencies generated for this target.
include CMakeFiles/lvnd.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/lvnd.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/lvnd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lvnd.dir/flags.make

CMakeFiles/lvnd.dir/src/callbacks.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/callbacks.c.o: ../../src/callbacks.c
CMakeFiles/lvnd.dir/src/callbacks.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/lvnd.dir/src/callbacks.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/callbacks.c.o -MF CMakeFiles/lvnd.dir/src/callbacks.c.o.d -o CMakeFiles/lvnd.dir/src/callbacks.c.o -c /home/samuliak/Documents/lvnd/src/callbacks.c

CMakeFiles/lvnd.dir/src/callbacks.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/callbacks.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/callbacks.c > CMakeFiles/lvnd.dir/src/callbacks.c.i

CMakeFiles/lvnd.dir/src/callbacks.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/callbacks.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/callbacks.c -o CMakeFiles/lvnd.dir/src/callbacks.c.s

CMakeFiles/lvnd.dir/src/context.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/context.c.o: ../../src/context.c
CMakeFiles/lvnd.dir/src/context.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/lvnd.dir/src/context.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/context.c.o -MF CMakeFiles/lvnd.dir/src/context.c.o.d -o CMakeFiles/lvnd.dir/src/context.c.o -c /home/samuliak/Documents/lvnd/src/context.c

CMakeFiles/lvnd.dir/src/context.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/context.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/context.c > CMakeFiles/lvnd.dir/src/context.c.i

CMakeFiles/lvnd.dir/src/context.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/context.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/context.c -o CMakeFiles/lvnd.dir/src/context.c.s

CMakeFiles/lvnd.dir/src/init.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/init.c.o: ../../src/init.c
CMakeFiles/lvnd.dir/src/init.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/lvnd.dir/src/init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/init.c.o -MF CMakeFiles/lvnd.dir/src/init.c.o.d -o CMakeFiles/lvnd.dir/src/init.c.o -c /home/samuliak/Documents/lvnd/src/init.c

CMakeFiles/lvnd.dir/src/init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/init.c > CMakeFiles/lvnd.dir/src/init.c.i

CMakeFiles/lvnd.dir/src/init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/init.c -o CMakeFiles/lvnd.dir/src/init.c.s

CMakeFiles/lvnd.dir/src/input.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/input.c.o: ../../src/input.c
CMakeFiles/lvnd.dir/src/input.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/lvnd.dir/src/input.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/input.c.o -MF CMakeFiles/lvnd.dir/src/input.c.o.d -o CMakeFiles/lvnd.dir/src/input.c.o -c /home/samuliak/Documents/lvnd/src/input.c

CMakeFiles/lvnd.dir/src/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/input.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/input.c > CMakeFiles/lvnd.dir/src/input.c.i

CMakeFiles/lvnd.dir/src/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/input.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/input.c -o CMakeFiles/lvnd.dir/src/input.c.s

CMakeFiles/lvnd.dir/src/menu_bar.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/menu_bar.c.o: ../../src/menu_bar.c
CMakeFiles/lvnd.dir/src/menu_bar.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/lvnd.dir/src/menu_bar.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/menu_bar.c.o -MF CMakeFiles/lvnd.dir/src/menu_bar.c.o.d -o CMakeFiles/lvnd.dir/src/menu_bar.c.o -c /home/samuliak/Documents/lvnd/src/menu_bar.c

CMakeFiles/lvnd.dir/src/menu_bar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/menu_bar.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/menu_bar.c > CMakeFiles/lvnd.dir/src/menu_bar.c.i

CMakeFiles/lvnd.dir/src/menu_bar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/menu_bar.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/menu_bar.c -o CMakeFiles/lvnd.dir/src/menu_bar.c.s

CMakeFiles/lvnd.dir/src/vector.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/vector.c.o: ../../src/vector.c
CMakeFiles/lvnd.dir/src/vector.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/lvnd.dir/src/vector.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/vector.c.o -MF CMakeFiles/lvnd.dir/src/vector.c.o.d -o CMakeFiles/lvnd.dir/src/vector.c.o -c /home/samuliak/Documents/lvnd/src/vector.c

CMakeFiles/lvnd.dir/src/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/vector.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/vector.c > CMakeFiles/lvnd.dir/src/vector.c.i

CMakeFiles/lvnd.dir/src/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/vector.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/vector.c -o CMakeFiles/lvnd.dir/src/vector.c.s

CMakeFiles/lvnd.dir/src/window.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/window.c.o: ../../src/window.c
CMakeFiles/lvnd.dir/src/window.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/lvnd.dir/src/window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/window.c.o -MF CMakeFiles/lvnd.dir/src/window.c.o.d -o CMakeFiles/lvnd.dir/src/window.c.o -c /home/samuliak/Documents/lvnd/src/window.c

CMakeFiles/lvnd.dir/src/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/window.c > CMakeFiles/lvnd.dir/src/window.c.i

CMakeFiles/lvnd.dir/src/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/window.c -o CMakeFiles/lvnd.dir/src/window.c.s

CMakeFiles/lvnd.dir/src/x11/x11_init.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/x11/x11_init.c.o: ../../src/x11/x11_init.c
CMakeFiles/lvnd.dir/src/x11/x11_init.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/lvnd.dir/src/x11/x11_init.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/x11/x11_init.c.o -MF CMakeFiles/lvnd.dir/src/x11/x11_init.c.o.d -o CMakeFiles/lvnd.dir/src/x11/x11_init.c.o -c /home/samuliak/Documents/lvnd/src/x11/x11_init.c

CMakeFiles/lvnd.dir/src/x11/x11_init.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/x11/x11_init.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/x11/x11_init.c > CMakeFiles/lvnd.dir/src/x11/x11_init.c.i

CMakeFiles/lvnd.dir/src/x11/x11_init.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/x11/x11_init.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/x11/x11_init.c -o CMakeFiles/lvnd.dir/src/x11/x11_init.c.s

CMakeFiles/lvnd.dir/src/x11/x11_window.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/x11/x11_window.c.o: ../../src/x11/x11_window.c
CMakeFiles/lvnd.dir/src/x11/x11_window.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/lvnd.dir/src/x11/x11_window.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/x11/x11_window.c.o -MF CMakeFiles/lvnd.dir/src/x11/x11_window.c.o.d -o CMakeFiles/lvnd.dir/src/x11/x11_window.c.o -c /home/samuliak/Documents/lvnd/src/x11/x11_window.c

CMakeFiles/lvnd.dir/src/x11/x11_window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/x11/x11_window.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/x11/x11_window.c > CMakeFiles/lvnd.dir/src/x11/x11_window.c.i

CMakeFiles/lvnd.dir/src/x11/x11_window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/x11/x11_window.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/x11/x11_window.c -o CMakeFiles/lvnd.dir/src/x11/x11_window.c.s

CMakeFiles/lvnd.dir/src/opengl/opengl.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/opengl/opengl.c.o: ../../src/opengl/opengl.c
CMakeFiles/lvnd.dir/src/opengl/opengl.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/lvnd.dir/src/opengl/opengl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/opengl/opengl.c.o -MF CMakeFiles/lvnd.dir/src/opengl/opengl.c.o.d -o CMakeFiles/lvnd.dir/src/opengl/opengl.c.o -c /home/samuliak/Documents/lvnd/src/opengl/opengl.c

CMakeFiles/lvnd.dir/src/opengl/opengl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/opengl/opengl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/opengl/opengl.c > CMakeFiles/lvnd.dir/src/opengl/opengl.c.i

CMakeFiles/lvnd.dir/src/opengl/opengl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/opengl/opengl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/opengl/opengl.c -o CMakeFiles/lvnd.dir/src/opengl/opengl.c.s

CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o: CMakeFiles/lvnd.dir/flags.make
CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o: ../../src/x11/opengl/x11_opengl.c
CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o: CMakeFiles/lvnd.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o -MF CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o.d -o CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o -c /home/samuliak/Documents/lvnd/src/x11/opengl/x11_opengl.c

CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/samuliak/Documents/lvnd/src/x11/opengl/x11_opengl.c > CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.i

CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/samuliak/Documents/lvnd/src/x11/opengl/x11_opengl.c -o CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.s

# Object files for target lvnd
lvnd_OBJECTS = \
"CMakeFiles/lvnd.dir/src/callbacks.c.o" \
"CMakeFiles/lvnd.dir/src/context.c.o" \
"CMakeFiles/lvnd.dir/src/init.c.o" \
"CMakeFiles/lvnd.dir/src/input.c.o" \
"CMakeFiles/lvnd.dir/src/menu_bar.c.o" \
"CMakeFiles/lvnd.dir/src/vector.c.o" \
"CMakeFiles/lvnd.dir/src/window.c.o" \
"CMakeFiles/lvnd.dir/src/x11/x11_init.c.o" \
"CMakeFiles/lvnd.dir/src/x11/x11_window.c.o" \
"CMakeFiles/lvnd.dir/src/opengl/opengl.c.o" \
"CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o"

# External object files for target lvnd
lvnd_EXTERNAL_OBJECTS =

../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/callbacks.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/context.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/init.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/input.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/menu_bar.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/vector.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/window.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/x11/x11_init.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/x11/x11_window.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/opengl/opengl.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/src/x11/opengl/x11_opengl.c.o
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/build.make
../lib/liblvnd.so.1: /usr/lib/x86_64-linux-gnu/libX11.so
../lib/liblvnd.so.1: /usr/lib/x86_64-linux-gnu/libXext.so
../lib/liblvnd.so.1: CMakeFiles/lvnd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/samuliak/Documents/lvnd/opengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C shared library ../lib/liblvnd.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lvnd.dir/link.txt --verbose=$(VERBOSE)
	$(CMAKE_COMMAND) -E cmake_symlink_library ../lib/liblvnd.so.1 ../lib/liblvnd.so.1 ../lib/liblvnd.so

../lib/liblvnd.so: ../lib/liblvnd.so.1
	@$(CMAKE_COMMAND) -E touch_nocreate ../lib/liblvnd.so

# Rule to build all files generated by this target.
CMakeFiles/lvnd.dir/build: ../lib/liblvnd.so
.PHONY : CMakeFiles/lvnd.dir/build

CMakeFiles/lvnd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lvnd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lvnd.dir/clean

CMakeFiles/lvnd.dir/depend:
	cd /home/samuliak/Documents/lvnd/opengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/samuliak/Documents/lvnd /home/samuliak/Documents/lvnd /home/samuliak/Documents/lvnd/opengl/build /home/samuliak/Documents/lvnd/opengl/build /home/samuliak/Documents/lvnd/opengl/build/CMakeFiles/lvnd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/lvnd.dir/depend

