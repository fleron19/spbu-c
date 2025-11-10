cmake_minimum_required(VERSION 3.25)

project(spbu-c C)

if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColourReset "${Esc}[m")
  set(Green       "${Esc}[32m")
  set(Orange       "${Esc}[33m")
endif()

file(GLOB DIRS LIST_DIRECTORIES true "src/*")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -pedantic -Wextra")
message(STATUS "Compiling with flags: ${CMAKE_C_FLAGS}")

foreach(DIR ${DIRS})
    if(EXISTS ${DIR}/CMakeLists.txt)
        message("${Green}Found CMake lists.txt in ${DIR}.${ColourReset}")
        add_subdirectory(${DIR})
    else()
        message("${Orange}CMakeLists.txt not found in ${DIR}.${ColourReset}")
    endif()
endforeach()
