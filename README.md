# DicomLab

## Objective:
A repository for playing with DICOM. My goal is not to develop a DICOM library from scratch because there are already great libraries for working with DICOM written in C++ and Python. Two of them that I am mostly familiar with are dcmtk and pydicom.

We use DICOM files a lot in medical image analysis projects. The main purpose of DicomLab is to develop tools and utilities that can be used when dealing with DICOM files. DICOM is a huge standard and learning every bits of it takes a life-time. DicomLab aims to use latest C++ standards along with the mature and robust Qt framework to develop various tools that can be used in Research and Development.

DicomLab has following projects:

## C++ project:
Uses dcmtk library as a base library for manipulating DICOM images. The main application is written in C++ and Qt framework. The application uses the plugin concept. Most of the command line tools available in dcmtk are written as a plugin that will be easy to use and play around.

Under cpp subfolder, add necessary Qt project structure, makefiles etc.

README.md

mainapp

resources

template_plugin

dcmtk_plugin_interface

.qmake

Makefile

CMakeLists.txt

echo_plugin

find_plugin

read_plugin

Separate plugins will be developed with separation of concern in mind so that it can be used in any application as a stand-along plugin.

Work in progress...


## Python project:
pydicom is used along with Qt to develop small applications to augument the community contributed applications. 

Under python subfolder, add necessary python scripts or projects that can be reused in any python application. These projects/scripts might be a single standalone python script or a full application that leverages Qt framework, pydicom and other Python packages.

README.md

utils

core

apps


### References
[dcmtk](https://dicom.offis.de/dcmtk.php.en)

[pydicom](https://pydicom.github.io/pydicom/stable/index.html)
