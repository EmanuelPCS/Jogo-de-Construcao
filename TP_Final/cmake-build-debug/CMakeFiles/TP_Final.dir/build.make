# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/178/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/178/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/TP_Final.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TP_Final.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TP_Final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP_Final.dir/flags.make

CMakeFiles/TP_Final.dir/main.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/main.cpp.o: ../main.cpp
CMakeFiles/TP_Final.dir/main.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP_Final.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/main.cpp.o -MF CMakeFiles/TP_Final.dir/main.cpp.o.d -o CMakeFiles/TP_Final.dir/main.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/main.cpp"

CMakeFiles/TP_Final.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/main.cpp" > CMakeFiles/TP_Final.dir/main.cpp.i

CMakeFiles/TP_Final.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/main.cpp" -o CMakeFiles/TP_Final.dir/main.cpp.s

CMakeFiles/TP_Final.dir/zonas.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/zonas.cpp.o: ../zonas.cpp
CMakeFiles/TP_Final.dir/zonas.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP_Final.dir/zonas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/zonas.cpp.o -MF CMakeFiles/TP_Final.dir/zonas.cpp.o.d -o CMakeFiles/TP_Final.dir/zonas.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/zonas.cpp"

CMakeFiles/TP_Final.dir/zonas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/zonas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/zonas.cpp" > CMakeFiles/TP_Final.dir/zonas.cpp.i

CMakeFiles/TP_Final.dir/zonas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/zonas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/zonas.cpp" -o CMakeFiles/TP_Final.dir/zonas.cpp.s

CMakeFiles/TP_Final.dir/ilhas.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/ilhas.cpp.o: ../ilhas.cpp
CMakeFiles/TP_Final.dir/ilhas.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TP_Final.dir/ilhas.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/ilhas.cpp.o -MF CMakeFiles/TP_Final.dir/ilhas.cpp.o.d -o CMakeFiles/TP_Final.dir/ilhas.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/ilhas.cpp"

CMakeFiles/TP_Final.dir/ilhas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/ilhas.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/ilhas.cpp" > CMakeFiles/TP_Final.dir/ilhas.cpp.i

CMakeFiles/TP_Final.dir/ilhas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/ilhas.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/ilhas.cpp" -o CMakeFiles/TP_Final.dir/ilhas.cpp.s

CMakeFiles/TP_Final.dir/trabalhador.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/trabalhador.cpp.o: ../trabalhador.cpp
CMakeFiles/TP_Final.dir/trabalhador.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TP_Final.dir/trabalhador.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/trabalhador.cpp.o -MF CMakeFiles/TP_Final.dir/trabalhador.cpp.o.d -o CMakeFiles/TP_Final.dir/trabalhador.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhador.cpp"

CMakeFiles/TP_Final.dir/trabalhador.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/trabalhador.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhador.cpp" > CMakeFiles/TP_Final.dir/trabalhador.cpp.i

CMakeFiles/TP_Final.dir/trabalhador.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/trabalhador.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhador.cpp" -o CMakeFiles/TP_Final.dir/trabalhador.cpp.s

CMakeFiles/TP_Final.dir/interface.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/interface.cpp.o: ../interface.cpp
CMakeFiles/TP_Final.dir/interface.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TP_Final.dir/interface.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/interface.cpp.o -MF CMakeFiles/TP_Final.dir/interface.cpp.o.d -o CMakeFiles/TP_Final.dir/interface.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/interface.cpp"

CMakeFiles/TP_Final.dir/interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/interface.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/interface.cpp" > CMakeFiles/TP_Final.dir/interface.cpp.i

CMakeFiles/TP_Final.dir/interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/interface.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/interface.cpp" -o CMakeFiles/TP_Final.dir/interface.cpp.s

CMakeFiles/TP_Final.dir/edificios.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/edificios.cpp.o: ../edificios.cpp
CMakeFiles/TP_Final.dir/edificios.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TP_Final.dir/edificios.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/edificios.cpp.o -MF CMakeFiles/TP_Final.dir/edificios.cpp.o.d -o CMakeFiles/TP_Final.dir/edificios.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/edificios.cpp"

CMakeFiles/TP_Final.dir/edificios.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/edificios.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/edificios.cpp" > CMakeFiles/TP_Final.dir/edificios.cpp.i

CMakeFiles/TP_Final.dir/edificios.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/edificios.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/edificios.cpp" -o CMakeFiles/TP_Final.dir/edificios.cpp.s

CMakeFiles/TP_Final.dir/trabalhadores.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/trabalhadores.cpp.o: ../trabalhadores.cpp
CMakeFiles/TP_Final.dir/trabalhadores.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/TP_Final.dir/trabalhadores.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/trabalhadores.cpp.o -MF CMakeFiles/TP_Final.dir/trabalhadores.cpp.o.d -o CMakeFiles/TP_Final.dir/trabalhadores.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhadores.cpp"

CMakeFiles/TP_Final.dir/trabalhadores.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/trabalhadores.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhadores.cpp" > CMakeFiles/TP_Final.dir/trabalhadores.cpp.i

CMakeFiles/TP_Final.dir/trabalhadores.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/trabalhadores.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/trabalhadores.cpp" -o CMakeFiles/TP_Final.dir/trabalhadores.cpp.s

CMakeFiles/TP_Final.dir/saves.cpp.o: CMakeFiles/TP_Final.dir/flags.make
CMakeFiles/TP_Final.dir/saves.cpp.o: ../saves.cpp
CMakeFiles/TP_Final.dir/saves.cpp.o: CMakeFiles/TP_Final.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/TP_Final.dir/saves.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TP_Final.dir/saves.cpp.o -MF CMakeFiles/TP_Final.dir/saves.cpp.o.d -o CMakeFiles/TP_Final.dir/saves.cpp.o -c "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/saves.cpp"

CMakeFiles/TP_Final.dir/saves.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP_Final.dir/saves.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/saves.cpp" > CMakeFiles/TP_Final.dir/saves.cpp.i

CMakeFiles/TP_Final.dir/saves.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP_Final.dir/saves.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/saves.cpp" -o CMakeFiles/TP_Final.dir/saves.cpp.s

# Object files for target TP_Final
TP_Final_OBJECTS = \
"CMakeFiles/TP_Final.dir/main.cpp.o" \
"CMakeFiles/TP_Final.dir/zonas.cpp.o" \
"CMakeFiles/TP_Final.dir/ilhas.cpp.o" \
"CMakeFiles/TP_Final.dir/trabalhador.cpp.o" \
"CMakeFiles/TP_Final.dir/interface.cpp.o" \
"CMakeFiles/TP_Final.dir/edificios.cpp.o" \
"CMakeFiles/TP_Final.dir/trabalhadores.cpp.o" \
"CMakeFiles/TP_Final.dir/saves.cpp.o"

# External object files for target TP_Final
TP_Final_EXTERNAL_OBJECTS =

TP_Final: CMakeFiles/TP_Final.dir/main.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/zonas.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/ilhas.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/trabalhador.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/interface.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/edificios.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/trabalhadores.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/saves.cpp.o
TP_Final: CMakeFiles/TP_Final.dir/build.make
TP_Final: CMakeFiles/TP_Final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable TP_Final"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP_Final.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP_Final.dir/build: TP_Final
.PHONY : CMakeFiles/TP_Final.dir/build

CMakeFiles/TP_Final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP_Final.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP_Final.dir/clean

CMakeFiles/TP_Final.dir/depend:
	cd "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final" "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final" "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug" "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug" "/media/manu/DATA/ISEC/Engenharia_Informatica/2_ano/1_Semestre/Programacao Orientada a Objetos/Meta2/TP_Final/cmake-build-debug/CMakeFiles/TP_Final.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/TP_Final.dir/depend
