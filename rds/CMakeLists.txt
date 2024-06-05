cmake_minimum_required(VERSION 3.23)
project(rds)
set(CMAKE_C_STANDARD 11)

#添加子目录
add_executable(toy_srv server.c server.h ae.h)
