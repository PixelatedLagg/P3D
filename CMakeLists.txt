cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")

project (p3d)

file(GLOB SOURCES src/*.c)

add_executable(p3d ${SOURCES})

target_include_directories(p3d
    PRIVATE 
        ${PROJECT_SOURCE_DIR}/src
)
target_link_libraries(p3d
    PRIVATE 
        mingw32
        ${CMAKE_SOURCE_DIR}/freeglut.dll
        opengl32
)