add_executable(main main.c)
add_library(binary binary.c)

target_link_libraries(main PRIVATE binary)
