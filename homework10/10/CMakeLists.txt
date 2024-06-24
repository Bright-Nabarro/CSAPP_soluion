cmake_minimum_required(VERSION 3.29)

project(cpfile)
set(SOURCES
    cpfile.c
    ../../csapp.c
)

add_executable(app ${SOURCES})
