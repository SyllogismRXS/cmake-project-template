###################################################
# Syllo Library
###################################################
set( LIBRARY_NAME_1 syllo )

FILE(GLOB SRCS *.cpp)

ADD_LIBRARY( ${LIBRARY_NAME_1} SHARED
  ${SRCS}
  )

target_link_libraries(${LIBRARY_NAME_1}
  )
