cmake_minimum_required(VERSION 2.8.3)

project(pathfinder CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE       Debug)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} " -std=c++11 ")

###########
## Settings
###########

set(RUNTIME_OUTPUT_DIRECTORY       "${PROJECT_BINARY_DIR}/bin")
set(LIBRARY_OUTPUT_DIRECTORY       "${PROJECT_BINARY_DIR}/lib")
set(ARCHIVE_OUTPUT_DIRECTORY       "${PROJECT_BINARY_DIR}/lib")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

include(pathfinder OPTIONAL)

set(PATHFINDER_CONFIG_PATH "${CMAKE_SOURCE_DIR}/config/" CACHE STRING "")

configure_file(${PROJECT_SOURCE_DIR}/cmake/pathfinder_config.h.cmake.in
               ${PROJECT_SOURCE_DIR}/include/pathfinder/core/pathfinder_config.h
              )

include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/include/")

##
## Mandatory dependencies
##

# Search for Eigen
find_package(Eigen3 REQUIRED)
include_directories(SYSTEM ${EIGEN3_INCLUDE_DIR})

##############
## config-yaml
##############

add_custom_target(TGT_build_libraries)

# config-yaml 
set(CONFIG-YAML_DIR "${PROJECT_SOURCE_DIR}/contrib/config-yaml")

add_subdirectory("${CONFIG-YAML_DIR}" EXCLUDE_FROM_ALL)
set_property(TARGET yaml-cpp APPEND_STRING PROPERTY COMPILE_FLAGS " -fPIC ")
add_dependencies(TGT_build_libraries TGT_config-yaml_build_libraries)

include_directories(SYSTEM "${CONFIG-YAML_DIR}/contrib/yaml-cpp/include/")
include_directories(SYSTEM "${CONFIG-YAML_DIR}/include/")
include_directories(SYSTEM "${PROJECT_SOURCE_DIR}/include/")

add_subdirectory(examples)
