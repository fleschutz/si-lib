# Build Instructions for CMake
# ============================

cmake_minimum_required(VERSION 3.10)

project(examples LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
if (MSVC)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /bigobj")
endif(MSVC)

include_directories(include/)

add_executable(program examples/main.cpp examples/astronomy.cpp examples/cheat_sheet.cpp examples/speeds.cpp examples/various.cpp)

install(TARGETS program DESTINATION . )

