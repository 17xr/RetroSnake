cmake_minimum_required(VERSION 3.28)
project(retro_snake)

set(CMAKE_CXX_STANDARD 23)

add_executable(retro_snake
        src/main.cpp
        src/additional/additional.cpp
        src/class/session.cpp
        src/class/snake.cpp)

target_link_libraries(retro_snake raylib)

set(source "${CMAKE_SOURCE_DIR}/resources")
set(destination "${CMAKE_CURRENT_BINARY_DIR}/resources")
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E create_symlink ${source} ${destination}
        DEPENDS ${destination}
        COMMENT "Symbolic link resources folder from ${source} => ${destination}")