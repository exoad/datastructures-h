cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_COMPILER "g++")
project(DataStructuresH, LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON) # if you are using sonarlint on vscode
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Release)
add_subdirectory(Introduction_To_C++)
add_subdirectory(Projects)
