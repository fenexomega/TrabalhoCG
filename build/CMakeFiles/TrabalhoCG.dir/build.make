# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.2

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
CMAKE_SOURCE_DIR = /home/jordy/Dropbox/TrabalhoCG

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jordy/Dropbox/TrabalhoCG/build

# Include any dependencies generated for this target.
include CMakeFiles/TrabalhoCG.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TrabalhoCG.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TrabalhoCG.dir/flags.make

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o: ../src/input/sysInput.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/input/sysInput.cpp

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/input/sysInput.cpp > CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.i

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/input/sysInput.cpp -o CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.s

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o: ../src/objects/Arrow.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/objects/Arrow.cpp

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/objects/Arrow.cpp > CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.i

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/objects/Arrow.cpp -o CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.s

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o: ../src/graphics/Texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Texture.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Texture.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Texture.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o: ../src/graphics/Transform.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Transform.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Transform.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Transform.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o: ../src/graphics/Program.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Program.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Program.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Program.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o: ../src/graphics/Shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Shader.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Shader.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Shader.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o: ../src/graphics/Mesh.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Mesh.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Mesh.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Mesh.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o: ../src/graphics/Window.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Window.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Window.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Window.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o: ../src/graphics/Camera.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/Camera.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/Camera.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/Camera.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o: ../src/graphics/SysGraphics.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/graphics/SysGraphics.cpp

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/graphics/SysGraphics.cpp > CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.i

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/graphics/SysGraphics.cpp -o CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.s

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o

CMakeFiles/TrabalhoCG.dir/src/main.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/main.cpp.o: ../src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/main.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/main.cpp

CMakeFiles/TrabalhoCG.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/main.cpp > CMakeFiles/TrabalhoCG.dir/src/main.cpp.i

CMakeFiles/TrabalhoCG.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/main.cpp -o CMakeFiles/TrabalhoCG.dir/src/main.cpp.s

CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/main.cpp.o

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o: ../src/Engine.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/Engine.cpp

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/Engine.cpp > CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.i

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/Engine.cpp -o CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.s

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o: ../src/utils/Timer.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/utils/Timer.cpp

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/utils/Timer.cpp > CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.i

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/utils/Timer.cpp -o CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.s

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o: ../src/utils/Logger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_14)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/utils/Logger.cpp

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/utils/Logger.cpp > CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.i

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/utils/Logger.cpp -o CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.s

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o: CMakeFiles/TrabalhoCG.dir/flags.make
CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o: ../src/game/Game.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles $(CMAKE_PROGRESS_15)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o -c /home/jordy/Dropbox/TrabalhoCG/src/game/Game.cpp

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jordy/Dropbox/TrabalhoCG/src/game/Game.cpp > CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.i

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jordy/Dropbox/TrabalhoCG/src/game/Game.cpp -o CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.s

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.requires:
.PHONY : CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.requires

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.provides: CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.requires
	$(MAKE) -f CMakeFiles/TrabalhoCG.dir/build.make CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.provides.build
.PHONY : CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.provides

CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.provides.build: CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o

# Object files for target TrabalhoCG
TrabalhoCG_OBJECTS = \
"CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/main.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o" \
"CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o"

# External object files for target TrabalhoCG
TrabalhoCG_EXTERNAL_OBJECTS =

TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/main.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/build.make
TrabalhoCG: /usr/lib64/libSDL2.so
TrabalhoCG: /usr/lib64/libSDL2_image.so
TrabalhoCG: /usr/lib64/libGLEW.so
TrabalhoCG: /usr/lib/libGL.so
TrabalhoCG: CMakeFiles/TrabalhoCG.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable TrabalhoCG"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TrabalhoCG.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TrabalhoCG.dir/build: TrabalhoCG
.PHONY : CMakeFiles/TrabalhoCG.dir/build

CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/input/sysInput.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/objects/Arrow.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Texture.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Transform.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Program.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Shader.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Mesh.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Window.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/Camera.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/graphics/SysGraphics.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/main.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/Engine.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/utils/Timer.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/utils/Logger.cpp.o.requires
CMakeFiles/TrabalhoCG.dir/requires: CMakeFiles/TrabalhoCG.dir/src/game/Game.cpp.o.requires
.PHONY : CMakeFiles/TrabalhoCG.dir/requires

CMakeFiles/TrabalhoCG.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TrabalhoCG.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TrabalhoCG.dir/clean

CMakeFiles/TrabalhoCG.dir/depend:
	cd /home/jordy/Dropbox/TrabalhoCG/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jordy/Dropbox/TrabalhoCG /home/jordy/Dropbox/TrabalhoCG /home/jordy/Dropbox/TrabalhoCG/build /home/jordy/Dropbox/TrabalhoCG/build /home/jordy/Dropbox/TrabalhoCG/build/CMakeFiles/TrabalhoCG.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TrabalhoCG.dir/depend

