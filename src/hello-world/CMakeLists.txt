set (APP_NAME syllo-hello-world)

file (GLOB SRCS *.cpp)
file (GLOB HDRS *.h)

add_executable(${APP_NAME} ${SRCS})

install(TARGETS ${APP_NAME} DESTINATION bin)
