cmake_minimum_required(VERSION 3.15)
project(cpp_file_scanner)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(cpp_file_scanner
    src/main.cpp
    src/file_scanner.cpp
    src/path_utils.cpp
)