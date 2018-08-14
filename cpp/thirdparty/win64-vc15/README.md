## Instructions for building dcmtk library from source

This folder contains dcmtk build using following configurations:

dcmtk source: dcmtk-3.6.1_20120222.tar.gz
Windows 10

Steps:
1. Create the following folder
C:\temp\dcmtk\build\install

2. Use the following in CMake settings:
set DCMTK_OVERWRITE_WIN32_COMPILER_FLAGS to OFF
Use Visual Studio 14 2015 as a native generator

Set source = C:\temp\dcmtk
Set build = C:\temp\dcmtk\build

3. After successfully building dcmtk, copy to C:\dev\dcmtk\build\install folder. Following sub-folders will be created:
bin : Contains all shared DLL files and executables command line dcmtk tools
etc : Configuration files
include: Include header files
lib: debug and release libraries that can be statically linked with other C++ applications
share: Other miscellaneous files
 
4. Create dcmtk.pri file in C:\dev\dcmtk. This file will list all the libraries that will be statically linked by Qt applications.


5. Use Qt 5.11 64 bits to statically link Qt application with dcmtk libraries.


6. To run the program successfully, copy all DLL files into the folder where DicomLab.exe is located.
Also copy the right version (debug/release) of plugins in dlplugins folder.

Other Files:
This folder also contains install.zip. This is already compiled DLL and Lib files based on above steps for building dcmtk.

It also contains intermediate CMake files that is generated during the build step.

