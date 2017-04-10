cmake_minimum_required (VERSION 2.8.9)

project (Arbolbinario)

include_directories(include)
set (SOURCES src/Nodo.cpp src/Arbolbinario.cpp src/main.cpp)
add_executable(Arbolbinario ${SOURCES})