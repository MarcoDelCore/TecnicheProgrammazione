# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Es_5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Es_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Es_5.dir/flags.make

CMakeFiles/Es_5.dir/main.c.obj: CMakeFiles/Es_5.dir/flags.make
CMakeFiles/Es_5.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Es_5.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\Es_5.dir\main.c.obj   -c "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\main.c"

CMakeFiles/Es_5.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Es_5.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\main.c" > CMakeFiles\Es_5.dir\main.c.i

CMakeFiles/Es_5.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Es_5.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\main.c" -o CMakeFiles\Es_5.dir\main.c.s

# Object files for target Es_5
Es_5_OBJECTS = \
"CMakeFiles/Es_5.dir/main.c.obj"

# External object files for target Es_5
Es_5_EXTERNAL_OBJECTS =

Es_5.exe: CMakeFiles/Es_5.dir/main.c.obj
Es_5.exe: CMakeFiles/Es_5.dir/build.make
Es_5.exe: CMakeFiles/Es_5.dir/linklibs.rsp
Es_5.exe: CMakeFiles/Es_5.dir/objects1.rsp
Es_5.exe: CMakeFiles/Es_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Es_5.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Es_5.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Es_5.dir/build: Es_5.exe

.PHONY : CMakeFiles/Es_5.dir/build

CMakeFiles/Es_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Es_5.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Es_5.dir/clean

CMakeFiles/Es_5.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05" "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05" "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug" "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug" "C:\Users\marco\Desktop\PoliTo\I Anno\II Semestre\Tecniche di programmazione\Projects\Lab01\Es05\cmake-build-debug\CMakeFiles\Es_5.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Es_5.dir/depend
