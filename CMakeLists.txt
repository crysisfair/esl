cmake_minimum_required (VERSION 3.0)
project(esl)
if(NOT DEFINED ENV{SYSTEMC})
    message(FATAL_ERROR "not defined environment variable:SYSTEMC")
endif()

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "-g")
endif()

include_directories($ENV{SYSTEMC}/include src lib)
aux_source_directory(src DIR_SRC)
link_directories($ENV{SYSTEMC}/lib-linux64)
add_subdirectory(lib)
add_compile_options(-g -Wall -Wextra -Wno-unused-parameter -Wno-unused-variable)
add_executable(esl ${DIR_SRC})
target_link_libraries(esl systemc lib)

set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/tests/build)
enable_testing()
add_subdirectory(tests)

