# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.21

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Hibrido.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Hibrido.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Hibrido.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Hibrido.dir/flags.make

CMakeFiles/Hibrido.dir/main.c.obj: CMakeFiles/Hibrido.dir/flags.make
CMakeFiles/Hibrido.dir/main.c.obj: ../main.c
CMakeFiles/Hibrido.dir/main.c.obj: CMakeFiles/Hibrido.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Hibrido.dir/main.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Hibrido.dir/main.c.obj -MF CMakeFiles\Hibrido.dir\main.c.obj.d -o CMakeFiles\Hibrido.dir\main.c.obj -c "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\main.c"

CMakeFiles/Hibrido.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hibrido.dir/main.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\main.c" > CMakeFiles\Hibrido.dir\main.c.i

CMakeFiles/Hibrido.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hibrido.dir/main.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\main.c" -o CMakeFiles\Hibrido.dir\main.c.s

CMakeFiles/Hibrido.dir/algoritmo.c.obj: CMakeFiles/Hibrido.dir/flags.make
CMakeFiles/Hibrido.dir/algoritmo.c.obj: ../algoritmo.c
CMakeFiles/Hibrido.dir/algoritmo.c.obj: CMakeFiles/Hibrido.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Hibrido.dir/algoritmo.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Hibrido.dir/algoritmo.c.obj -MF CMakeFiles\Hibrido.dir\algoritmo.c.obj.d -o CMakeFiles\Hibrido.dir\algoritmo.c.obj -c "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\algoritmo.c"

CMakeFiles/Hibrido.dir/algoritmo.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hibrido.dir/algoritmo.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\algoritmo.c" > CMakeFiles\Hibrido.dir\algoritmo.c.i

CMakeFiles/Hibrido.dir/algoritmo.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hibrido.dir/algoritmo.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\algoritmo.c" -o CMakeFiles\Hibrido.dir\algoritmo.c.s

CMakeFiles/Hibrido.dir/utils.c.obj: CMakeFiles/Hibrido.dir/flags.make
CMakeFiles/Hibrido.dir/utils.c.obj: ../utils.c
CMakeFiles/Hibrido.dir/utils.c.obj: CMakeFiles/Hibrido.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Hibrido.dir/utils.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Hibrido.dir/utils.c.obj -MF CMakeFiles\Hibrido.dir\utils.c.obj.d -o CMakeFiles\Hibrido.dir\utils.c.obj -c "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\utils.c"

CMakeFiles/Hibrido.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hibrido.dir/utils.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\utils.c" > CMakeFiles\Hibrido.dir\utils.c.i

CMakeFiles/Hibrido.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hibrido.dir/utils.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\utils.c" -o CMakeFiles\Hibrido.dir\utils.c.s

CMakeFiles/Hibrido.dir/funcao.c.obj: CMakeFiles/Hibrido.dir/flags.make
CMakeFiles/Hibrido.dir/funcao.c.obj: ../funcao.c
CMakeFiles/Hibrido.dir/funcao.c.obj: CMakeFiles/Hibrido.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Hibrido.dir/funcao.c.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Hibrido.dir/funcao.c.obj -MF CMakeFiles\Hibrido.dir\funcao.c.obj.d -o CMakeFiles\Hibrido.dir\funcao.c.obj -c "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\funcao.c"

CMakeFiles/Hibrido.dir/funcao.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Hibrido.dir/funcao.c.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\funcao.c" > CMakeFiles\Hibrido.dir\funcao.c.i

CMakeFiles/Hibrido.dir/funcao.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Hibrido.dir/funcao.c.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\funcao.c" -o CMakeFiles\Hibrido.dir\funcao.c.s

# Object files for target Hibrido
Hibrido_OBJECTS = \
"CMakeFiles/Hibrido.dir/main.c.obj" \
"CMakeFiles/Hibrido.dir/algoritmo.c.obj" \
"CMakeFiles/Hibrido.dir/utils.c.obj" \
"CMakeFiles/Hibrido.dir/funcao.c.obj"

# External object files for target Hibrido
Hibrido_EXTERNAL_OBJECTS =

Hibrido.exe: CMakeFiles/Hibrido.dir/main.c.obj
Hibrido.exe: CMakeFiles/Hibrido.dir/algoritmo.c.obj
Hibrido.exe: CMakeFiles/Hibrido.dir/utils.c.obj
Hibrido.exe: CMakeFiles/Hibrido.dir/funcao.c.obj
Hibrido.exe: CMakeFiles/Hibrido.dir/build.make
Hibrido.exe: CMakeFiles/Hibrido.dir/linklibs.rsp
Hibrido.exe: CMakeFiles/Hibrido.dir/objects1.rsp
Hibrido.exe: CMakeFiles/Hibrido.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable Hibrido.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Hibrido.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Hibrido.dir/build: Hibrido.exe
.PHONY : CMakeFiles/Hibrido.dir/build

CMakeFiles/Hibrido.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Hibrido.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Hibrido.dir/clean

CMakeFiles/Hibrido.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido" "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido" "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug" "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug" "C:\Users\hugoj\Desktop\ISEC\OneDrive - ISEC\2_ANO\1_SEMESTRE\IIA\TP2_IIA_2021_22\IIA\Hibrido\cmake-build-debug\CMakeFiles\Hibrido.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Hibrido.dir/depend
