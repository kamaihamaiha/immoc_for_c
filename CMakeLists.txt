cmake_minimum_required(VERSION 3.17)


get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
string(REPLACE " " "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

include_directories("chapter5/include")
include_directories("chapter6/include")
include_directories("chapter10/include")
include_directories("chapter12/tinycthread/include")

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/chapter*/*.c"
        "${CMAKE_CURRENT_SOURCE_DIR}/books/chapter*/*/*.c"
        )
foreach(file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file} chapter5/src/Factorial.c chapter12/tinycthread/tinycthread.c)
    target_compile_definitions(${name} PUBLIC DEBUG)

    if (UNIX OR Linux)
        target_link_libraries(${name} pthread)
    endif ()
endforeach()