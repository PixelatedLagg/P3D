set(CMAKE_GENERATOR, "mingw32-make")
cmake_minimum_required(VERSION 3.22.5)
set(CMAKE_CXX_COMPILER "g++")
project(p3d)

file(GLOB SOURCES src/*.cpp)

add_executable(p3d ${SOURCES})

target_include_directories(p3d
    PRIVATE 
        src/include
        C:/MinGW/x86_64-w64-mingw32/include/GL
)


find_package(OpenGL REQUIRED)

target_link_libraries(p3d
    PUBLIC 
        mingw32
        C:/MinGW/x86_64-w64-mingw32/include/GL/Glut32.lib
)