# Install script for directory: /Users/anqizheng/desktop/computer graphics/CS3451/tutorials

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
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

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/Library/Developer/CommandLineTools/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_camera/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_cpp101/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_hello_glsl/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_lighting/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_matrix/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_mesh/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_opengl/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_shader_programming/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_texture/cmake_install.cmake")
  include("/Users/anqizheng/desktop/computer graphics/CS3451/build/tutorials/tutorial_transform/cmake_install.cmake")

endif()

