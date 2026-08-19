cmake_minimum_required(VERSION 3.10)

project(pn-lang LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(parse core/parse.cpp)