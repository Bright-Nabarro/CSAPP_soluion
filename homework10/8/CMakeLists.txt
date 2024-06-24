cmake_minimum_required(VERSION 3.29)

project(statcheck)

set(SRC fstatcheck.c ../../csapp.c)

add_executable(app ${SRC})