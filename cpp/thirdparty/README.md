## Instructions for building dcmtk library from source

The build that is currently used in DicomLab is an older version of dcmtk (dcmtk-3.6.1_20120222.tar.gz). The newer builds are not working for me while integrating with Qt and modern C++ compilers.

Windows:
1. Create the following folder
C:\dev\dcmtk\build\install

2. Use the following in CMake settings:
set DCMTK_OVERWRITE_WIN32_COMPILER_FLAGS to OFF
Use Visual Studio 14 2015 as a native generator

Set source = C:\dev\dcmtk
Set build = C:\dev\dcmtk\build


3. After successfully building dcmtk, navigate to C:\dev\dcmtk\build\install folder. Following sub-folders will be created:
bin : Contains all shared DLL files and executables command line dcmtk tools
etc : Configuration files
include: Include header files
lib: debug and release libraries that can be statically linked with other C++ applications
share: Other miscellaneous files
 

4. Create dcmtk.pri file in C:\dev\dcmtk. This file will list all the libraries that will be statically linked by Qt applications.


5. Use Qt 5.6 32 bits to statically link Qt application with dcmtk libraries.


6. To run the program successfully, copy all DLL files into the folder where DicomLab.exe is located.
Also copy the right version (debug/release) of plugins in dlplugins folder.

To troubleshoot errors that is encountered while building dcmtk from source, refer the following Stackoverflow discussion:
Reference: https://stackoverflow.com/questions/28106665/dcmtk-character-set-unicode-error
