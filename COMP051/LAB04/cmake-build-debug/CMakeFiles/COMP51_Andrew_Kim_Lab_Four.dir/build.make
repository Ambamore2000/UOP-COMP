# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\flags.make

CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.obj: CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\flags.make
CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.obj: ..\main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/COMP51_Andrew_Kim_Lab_Four.dir/main.cpp.obj"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.obj /FdCMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\ /FS -c C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\main.cpp
<<

CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/COMP51_Andrew_Kim_Lab_Four.dir/main.cpp.i"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\bin\Hostx86\x86\cl.exe" > CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\main.cpp
<<

CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/COMP51_Andrew_Kim_Lab_Four.dir/main.cpp.s"
	"C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\bin\Hostx86\x86\cl.exe" @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.s /c C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\main.cpp
<<

# Object files for target COMP51_Andrew_Kim_Lab_Four
COMP51_Andrew_Kim_Lab_Four_OBJECTS = \
"CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.obj"

# External object files for target COMP51_Andrew_Kim_Lab_Four
COMP51_Andrew_Kim_Lab_Four_EXTERNAL_OBJECTS =

COMP51_Andrew_Kim_Lab_Four.exe: CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\main.cpp.obj
COMP51_Andrew_Kim_Lab_Four.exe: CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\build.make
COMP51_Andrew_Kim_Lab_Four.exe: CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable COMP51_Andrew_Kim_Lab_Four.exe"
	"C:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir --rc="C:\PROGRA~2\Windows Kits\10\bin\10.0.18362.0\x86\rc.exe" --mt="C:\PROGRA~2\Windows Kits\10\bin\10.0.18362.0\x86\mt.exe" --manifests  -- "C:\PROGRA~2\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\bin\Hostx86\x86\link.exe" /nologo @CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\objects1.rsp @<<
 /out:COMP51_Andrew_Kim_Lab_Four.exe /implib:COMP51_Andrew_Kim_Lab_Four.lib /pdb:C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug\COMP51_Andrew_Kim_Lab_Four.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\build: COMP51_Andrew_Kim_Lab_Four.exe

.PHONY : CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\build

CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\cmake_clean.cmake
.PHONY : CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\clean

CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug C:\Users\Andki\CLionProjects\COMP51_Andrew_Kim_Lab_Four\cmake-build-debug\CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\COMP51_Andrew_Kim_Lab_Four.dir\depend

