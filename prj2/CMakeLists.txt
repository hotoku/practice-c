add_library(func STATIC func.c)
add_executable(prj2 main.c)
target_link_libraries(prj2 func)
