cmake_minimum_required (VERSION 2.6)
set (PROJECT_NAME "syllo")
project (${PROJECT_NAME})

set(SYLLO_VERSION_MAJOR "0")
set(SYLLO_VERSION_MINOR "0")
set(SYLLO_VERSION_PATCH "0")
set(SYLLO_VERSION "${SYLLO_VERSION_MAJOR}.${SYLLO_VERSION_MINOR}.${SYLLO_VERSION_PATCH}")
set(SYLLO_VERSION_DATE "2012.12.30")

# give SYLLO 1 series a few more soversions
set(SYLLO_SOVERSION "00")

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set (CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "default install path" FORCE )
endif()

# fetch all the local directories for generated code
get_filename_component(SYLLO_LIB_DIR ./lib ABSOLUTE)
get_filename_component(SYLLO_BIN_DIR ./bin ABSOLUTE)
get_filename_component(SYLLO_INC_DIR ./include ABSOLUTE)
get_filename_component(SYLLO_SRC_DIR ./src ABSOLUTE)
get_filename_component(SYLLO_SHARE_DIR ./share ABSOLUTE)
get_filename_component(SYLLO_BUILD_DIR ./build ABSOLUTE)
get_filename_component(SYLLO_SCRIPTS_DIR ./scripts ABSOLUTE)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

set(CMAKE_CXX_FLAGS "-g -Wall")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall") # -fprofile-arcs -ftest-coverage")

set(EXECUTABLE_OUTPUT_PATH ${SYLLO_BIN_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SYLLO_LIB_DIR})

## set the cmake defaults for libraries and binaries
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${SYLLO_LIB_DIR} CACHE PATH
  "Output directory for the dynamic libraries" )
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${SYLLO_BIN_DIR} CACHE PATH
  "Output directory for the binaries" )
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${SYLLO_LIB_DIR} CACHE PATH
  "Output directory for the static libraries (archives)" )

INSTALL(
  DIRECTORY ${SYLLO_INC_DIR}/syllo
  DESTINATION include
)

INSTALL(
  DIRECTORY ${SYLLO_LIB_DIR}/
  DESTINATION lib
  )

INSTALL(
  DIRECTORY ${SYLLO_BIN_DIR}/
  DESTINATION bin
)

## let cmake know where the headers are
include_directories(${SYLLO_INC_DIR})

add_subdirectory(src)

########################################
# Binary installation generation
########################################
set(PACKAGE_ARCHITECTURE "" CACHE STRING "Package architecture")
if (NOT "${PACKAGE_ARCHITECTURE}" STREQUAL "")
  set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "${PACKAGE_ARCHITECTURE}")
else()
  set(PACKAGE_ARCHITECTURE "${CMAKE_SYSTEM_PROCESSOR}")
endif()

set(VERSION "1.0.1")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "DEB")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Kevin DeMarco")
set(CPACK_PACKAGE_VENDOR "syllo company")
set(CPACK_PACKAGING_INSTALL_PREFIX "/usr")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${PACKAGE_ARCHITECTURE}")
include(CPack)
