# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/risc_v_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/risc_v_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/risc_v_new.dir/flags.make

CMakeFiles/risc_v_new.dir/main.cpp.o: CMakeFiles/risc_v_new.dir/flags.make
CMakeFiles/risc_v_new.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/risc_v_new.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/risc_v_new.dir/main.cpp.o -c /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/main.cpp

CMakeFiles/risc_v_new.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/risc_v_new.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/main.cpp > CMakeFiles/risc_v_new.dir/main.cpp.i

CMakeFiles/risc_v_new.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/risc_v_new.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/main.cpp -o CMakeFiles/risc_v_new.dir/main.cpp.s

# Object files for target risc_v_new
risc_v_new_OBJECTS = \
"CMakeFiles/risc_v_new.dir/main.cpp.o"

# External object files for target risc_v_new
risc_v_new_EXTERNAL_OBJECTS =

risc_v_new: CMakeFiles/risc_v_new.dir/main.cpp.o
risc_v_new: CMakeFiles/risc_v_new.dir/build.make
risc_v_new: CMakeFiles/risc_v_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable risc_v_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/risc_v_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/risc_v_new.dir/build: risc_v_new

.PHONY : CMakeFiles/risc_v_new.dir/build

CMakeFiles/risc_v_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/risc_v_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/risc_v_new.dir/clean

CMakeFiles/risc_v_new.dir/depend:
	cd /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug /Users/mulinjiu/Desktop/HXL/大一暑/PPCA/risc_v_new/cmake-build-debug/CMakeFiles/risc_v_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/risc_v_new.dir/depend

