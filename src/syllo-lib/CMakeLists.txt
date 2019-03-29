###################################################
# Syllo Library
###################################################
set(LIBRARY_NAME syllo)

FILE(GLOB SRCS *.cpp)

ADD_LIBRARY( ${LIBRARY_NAME} SHARED
  ${SRCS}
  )

target_link_libraries(
  ${LIBRARY_NAME}
  PUBLIC
  PRIVATE
  )

target_include_directories(
  ${LIBRARY_NAME}
  PUBLIC
  "$<INSTALL_INTERFACE:include>"
  "$<BUILD_INTERFACE:${PROJECT_INCLUDE_DIR}>"
)

set_target_properties(
  ${LIBRARY_NAME}
  PROPERTIES
  SOVERSION ${PROJECT_VERSION}
  VERSION ${PROJECT_VERSION}
  )

install(TARGETS ${LIBRARY_NAME}
  EXPORT ${PROJECT_NAME}-targets
  RUNTIME DESTINATION bin
  LIBRARY DESTINATION lib
  )
