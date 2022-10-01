cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 20)

project(Arrabbiata)

# Includes
include_directories(Arrabbiata PRIVATE "src/")

include_directories(Arrabbiata PRIVATE "lib/bgfx/include")
include_directories(Arrabbiata PRIVATE "lib/bx/include")
include_directories(Arrabbiata PRIVATE "lib/glfw/include")
include_directories(Arrabbiata PRIVATE "lib/bimg/include")
include_directories(Arrabbiata PRIVATE "lib/glm")

# Create .exe
add_executable(Arrabbiata
        src/main.cpp src/main.hpp src/global.hpp src/global.hpp
        src/platform/platform.cpp src/platform/platform.hpp
        src/gfx/renderer.cpp src/gfx/renderer.hpp
        src/input/input.cpp src/input/input.hpp
        src/time/time.cpp src/time/time.hpp
        src/gfx/vertex.hpp
        src/camera/camera.cpp src/camera/camera.hpp
        src/atlas/atlas.cpp src/atlas/atlas.hpp
        src/resource_loader/resource_loader.cpp src/resource_loader/resource_loader.hpp)

# Links libraries
target_link_directories(Arrabbiata PRIVATE "lib/bgfx/.build/")
target_link_directories(Arrabbiata PRIVATE "lib/glfw/.build/")
target_link_libraries(Arrabbiata bgfx bx bimg_decode bimg glfw3)