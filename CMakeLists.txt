cmake_minimum_required(VERSION 3.30)

project(c-practice LANGUAGES C)
set(CMAKE_C_STANDARD 99)

set(SANITIZE_FLAGS "-fsanitize=leak -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${SANITIZE_FLAGS}")

add_subdirectory(prj1)
add_subdirectory(prj2)
add_subdirectory(prj3)
add_subdirectory(prj4)
add_subdirectory(prj5)
add_subdirectory(prj6)
add_subdirectory(prj7)
add_subdirectory(prj8)
add_subdirectory(prj9)
