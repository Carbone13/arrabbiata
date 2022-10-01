cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)

project(Arrabbiata)

# Includes
include_directories(Arrabbiata PRIVATE "src/")

include_directories(Arrabbiata PRIVATE "lib/bgfx/include")
include_directories(Arrabbiata PRIVATE "lib/glfw/include")
include_directories(Arrabbiata PRIVATE "lib/bimg/include")
include_directories(Arrabbiata PRIVATE "lib/glm")

# Create .exe
add_executable(Arrabbiata
        src/main.cpp src/main.hpp)

# Links libraries
target_link_directories(Arrabbiata PRIVATE "lib/bgfx/.build/")
target_link_directories(Arrabbiata PRIVATE "lib/glfw/.build/")
target_link_libraries(Arrabbiata bgfx bx bimg_decode bimg glfw3)