cmake_minimum_required(VERSION 3.15)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
STRING(REPLACE "" "_" ProjectId ${ProjectId})
project(${ProjectId} C)

set(CMAKE_C_STANDARD 11)

file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.C")
FOREACH (file ${files})
    get_filename_component(name ${file} NAME)
    add_executable(${name} ${file})
ENDFOREACH ()