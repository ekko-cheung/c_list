cmake_minimum_required(VERSION 3.5)

project(c_list)

file(REMOVE_RECURSE "build")
file(GLOB_RECURSE SRC *.c)

add_executable(example ${SRC})