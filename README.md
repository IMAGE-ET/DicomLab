# DicomLab

## Objectives:
A repository for playing with DICOM. My goal is not to develop a DICOM library from scratch because there are already great libraries for working with DICOM written in C++ and Python. Two of them that I am mostly familiar with are dcmtk and pydicom.

We use DICOM files a lot in medical image analysis projects. The main purpose of DicomLab is to develop tools and utilities that can be used when dealing with DICOM files. DICOM is a huge standard and learning every bits of it takes a life-time. DicomLab aims to use latest C++ standards along with the mature and robust Qt framework to develop various tools that can be used in Research and Development.

## Projects:
Qt and C++ project:
Uses dcmtk library as a base library for manipulating DICOM images. The main application is written in C++ and Qt framework. The application uses the plugin concept. Most of the command line tools available in dcmtk are written as a plugin that will be easy to use and play around.

Python project:
pydicom is used along with Qt to develop small applications to augument the community contributed applications. 

Project structure:
As the same repository would host both C++ and Python projects, following structure can be used:

On a high level, it has sub-folders for specific programming language that will be used to write tools and utilities.

DicomLab
|___C++
|___Python

Under C++, add necessary Qt project structure, makefiles etc.
C++
|___README.md
|___mainapp
|___resources
|___template_plugin
|___dcmtk_plugin_interface
|___.qmake
|___Makefile
|___CMakeLists.txt
|___echo_plugin
|___find_plugin
|___read_plugin

Separate plugins shall be developed with separation of concern in mind so that it can be used in any application as a stand-along plugin.

Python
|___README.md
|___utils
|___core
|___apps

Under Python, add necessary python scripts or projects that can be reused in any python application. These projects/scripts might be a single standalong python script or a full application that leverages Qt framework, pydicom and other Python packages.

### References
[dcmtk](https://dicom.offis.de/dcmtk.php.en)
[pydicom](https://pydicom.github.io/pydicom/stable/index.html)