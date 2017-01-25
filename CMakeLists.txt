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

set(CMAKE_INSTALL_PREFIX /usr/local)

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

INSTALL(DIRECTORY ${SYLLO_INC_DIR} DESTINATION ${CMAKE_INSTALL_PREFIX}
  FILES_MATCHING REGEX .*\\.h|.*\\.proto
)

#INSTALL(TARGETS ${} 
#  LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
#  PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
#)

install(DIRECTORY ${SYLLO_LIB_DIR}/ 
  DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
  )

## let cmake know where the headers are
include_directories(${SYLLO_INC_DIR})

## copy to syllo/include
file(GLOB_RECURSE INCLUDE_FILES RELATIVE ${SYLLO_SRC_DIR} src/*.h)
foreach(I ${INCLUDE_FILES})
  configure_file(${SYLLO_SRC_DIR}/${I} ${SYLLO_INC_DIR}/syllo/${I} @ONLY)
endforeach()

add_subdirectory(src)

########################################
# Binary installation generation
########################################
set(VERSION "1.0.1")
set(CPACK_PACKAGE_VERSION ${VERSION})
set(CPACK_GENERATOR "RPM")
set(CPACK_PACKAGE_NAME ${PROJECT_NAME})
set(CPACK_PACKAGE_RELEASE 1)
set(CPACK_PACKAGE_CONTACT "Kevin DeMarco")
set(CPACK_PACKAGE_VENDOR "syllo company")
set(CPACK_PACKAGING_INSTALL_PREFIX ${CMAKE_INSTALL_PREFIX})
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${CPACK_PACKAGE_VERSION}-${CPACK_PACKAGE_RELEASE}.${CMAKE_SYSTEM_PROCESSOR}")
include(CPack)
