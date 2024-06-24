cmake_minimum_required(VERSION 3.29)

project(mem_stm)

option(USE_TEST_MEM "small memory check handlely" NO)
#option(ENALBE_DEBUG_MODE NO)
aux_source_directory(. DIR_SRCS)

if(USE_TEST_MEM)
    add_definitions(-DTEST_MEM=1)
endif()

add_executable(app ${DIR_SRCS})

#if(ENABLE_DEBUG_MODE)
#    target_compile_definitions(app PRIVATE DEBUG=1)
#endif()