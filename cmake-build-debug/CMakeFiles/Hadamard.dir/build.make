# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/CosmosRedshift/projects/Hadamard

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/CosmosRedshift/projects/Hadamard/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Hadamard.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Hadamard.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hadamard.dir/flags.make

CMakeFiles/Hadamard.dir/main.cpp.o: CMakeFiles/Hadamard.dir/flags.make
CMakeFiles/Hadamard.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Hadamard.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hadamard.dir/main.cpp.o -c /Users/CosmosRedshift/projects/Hadamard/main.cpp

CMakeFiles/Hadamard.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hadamard.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/CosmosRedshift/projects/Hadamard/main.cpp > CMakeFiles/Hadamard.dir/main.cpp.i

CMakeFiles/Hadamard.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hadamard.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/CosmosRedshift/projects/Hadamard/main.cpp -o CMakeFiles/Hadamard.dir/main.cpp.s

CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o: CMakeFiles/Hadamard.dir/flags.make
CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o: ../Complex/Complex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o -c /Users/CosmosRedshift/projects/Hadamard/Complex/Complex.cpp

CMakeFiles/Hadamard.dir/Complex/Complex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hadamard.dir/Complex/Complex.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/CosmosRedshift/projects/Hadamard/Complex/Complex.cpp > CMakeFiles/Hadamard.dir/Complex/Complex.cpp.i

CMakeFiles/Hadamard.dir/Complex/Complex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hadamard.dir/Complex/Complex.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/CosmosRedshift/projects/Hadamard/Complex/Complex.cpp -o CMakeFiles/Hadamard.dir/Complex/Complex.cpp.s

CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o: CMakeFiles/Hadamard.dir/flags.make
CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o: ../HmdVector/HmdVector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o -c /Users/CosmosRedshift/projects/Hadamard/HmdVector/HmdVector.cpp

CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/CosmosRedshift/projects/Hadamard/HmdVector/HmdVector.cpp > CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.i

CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/CosmosRedshift/projects/Hadamard/HmdVector/HmdVector.cpp -o CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.s

CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o: CMakeFiles/Hadamard.dir/flags.make
CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o: ../HmdMatrix/HmdMatrix.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o -c /Users/CosmosRedshift/projects/Hadamard/HmdMatrix/HmdMatrix.cpp

CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/CosmosRedshift/projects/Hadamard/HmdMatrix/HmdMatrix.cpp > CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.i

CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/CosmosRedshift/projects/Hadamard/HmdMatrix/HmdMatrix.cpp -o CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.s

# Object files for target Hadamard
Hadamard_OBJECTS = \
"CMakeFiles/Hadamard.dir/main.cpp.o" \
"CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o" \
"CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o" \
"CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o"

# External object files for target Hadamard
Hadamard_EXTERNAL_OBJECTS =

Hadamard: CMakeFiles/Hadamard.dir/main.cpp.o
Hadamard: CMakeFiles/Hadamard.dir/Complex/Complex.cpp.o
Hadamard: CMakeFiles/Hadamard.dir/HmdVector/HmdVector.cpp.o
Hadamard: CMakeFiles/Hadamard.dir/HmdMatrix/HmdMatrix.cpp.o
Hadamard: CMakeFiles/Hadamard.dir/build.make
Hadamard: CMakeFiles/Hadamard.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Hadamard"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Hadamard.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hadamard.dir/build: Hadamard

.PHONY : CMakeFiles/Hadamard.dir/build

CMakeFiles/Hadamard.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Hadamard.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Hadamard.dir/clean

CMakeFiles/Hadamard.dir/depend:
	cd /Users/CosmosRedshift/projects/Hadamard/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/CosmosRedshift/projects/Hadamard /Users/CosmosRedshift/projects/Hadamard /Users/CosmosRedshift/projects/Hadamard/cmake-build-debug /Users/CosmosRedshift/projects/Hadamard/cmake-build-debug /Users/CosmosRedshift/projects/Hadamard/cmake-build-debug/CMakeFiles/Hadamard.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Hadamard.dir/depend

