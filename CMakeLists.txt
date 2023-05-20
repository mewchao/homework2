cmake_minimum_required(VERSION 3.24)
project(homework2)

set(CMAKE_CXX_STANDARD 11)

# 指定源文件编码格式为 GBK
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:gbk>")

add_executable(homework2 student1.cpp student2.cpp student.h)
