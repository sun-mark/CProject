
cmake_minimum_required(VERSION 3.22)
get_filename_component(ProjectId ${CMAKE_CURRENT_SOURCE_DIR} NAME)
STRING(REPLACE "" "_" ProjectId ${ProjectId})
project(${ProjectId} C)
set(CMAKE_C_STANDARD 11)


include_directories("include")
include_directories("tinycthread/include")
file(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.C")
#FOREACH (file ${files})
#    get_filename_component(name ${file} NAME)
#    add_executable(${name} ${file} include/tinycthread.c)
#ENDFOREACH ()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
INCLUDE_DIRECTORIES(${GTK3_INCLUDE_DIRS})
LINK_DIRECTORIES(${GTK3_CFLAGS_OTHER})
set(CMAKE_C_FLAGS_RELEASE -mwindows)
if (UNIX OR Linux)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
ENDIF ()
# 遍历项目根目录下所有的 .c 文件
#file(GLOB_RECURSE files *.c)
#foreach (file ${files})
#    string(REGEX REPLACE ".+/(.+)\\..*" "\\1" exe ${file})
#    #    message(------------ 文件: ${file})
#    if (${file} MATCHES cmake-build-debug)
#        CONTINUE()
#    endif ()
#
#    # 源文件名称中包含[.c]的文件
#    if (${file} MATCHES .c)
#        get_filename_component(name ${file} NAME)
#        add_executable(${exe} ${file})
#        target_link_libraries(${exe} ${GTK3_LIBRARIES})
#        message(------------ 添加文件: ${file})
#        #        if (UNIX OR Linux)
#        #            target_link_libraries(${exe}
#        #                    pthread
#        #                    ${CONAN_LIBS})
#        #        endif ()
#        continue()
#    endif ()
#    message(************ 跳过文件: ${file})
#endforeach ()
add_executable(main ${files})
target_link_libraries(main ${GTK3_LIBRARIES})

# 需要多个文件合作生成一个可执行文件,需要自己添加
#add_executable(extern1 02_keyword/extern1.c 02_keyword/extern2.c)
