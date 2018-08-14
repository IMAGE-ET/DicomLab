# Install script for directory: C:/temp/dcmtk/3.6.1

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/DCMTK")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xincludex" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/dcmtk/config" TYPE FILE FILES "C:/temp/dcmtk/3.6.1/build/config/include/dcmtk/config/osconfig.h")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xdocx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/doc/dcmtk" TYPE FILE FILES
    "C:/temp/dcmtk/3.6.1/ANNOUNCE.361"
    "C:/temp/dcmtk/3.6.1/CHANGES.361"
    "C:/temp/dcmtk/3.6.1/COPYRIGHT"
    "C:/temp/dcmtk/3.6.1/FAQ"
    "C:/temp/dcmtk/3.6.1/HISTORY"
    "C:/temp/dcmtk/3.6.1/VERSION"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/temp/dcmtk/3.6.1/build/config/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/ofstd/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/oflog/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmdata/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmimgle/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmimage/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmjpeg/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmjpls/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmtls/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmnet/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmsr/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmsign/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmwlm/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmqrdb/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/dcmpstat/cmake_install.cmake")
  include("C:/temp/dcmtk/3.6.1/build/doxygen/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/temp/dcmtk/3.6.1/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
