add_executable(stackBraces stackBraces.c)
add_library(stack stack.c)

target_link_libraries(stackBraces PRIVATE stack)
