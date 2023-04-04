cmake_minimum_required(VERSION 3.26)
project(Ball_Killer)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES "src/*")
add_executable(${PROJECT_NAME} ${SOURCES})



# Set the path to the Raylib library
# I have raylib installed with msys2, so this are the pads for me.
set(RAYLIB_INCLUDE_DIR "C:/msys64/mingw64/include")
set(RAYLIB_LIBRARY "C:/msys64/mingw64/lib/libraylib.dll.a")

# Set the include directories and libraries for the project
include_directories(${RAYLIB_INCLUDE_DIR})
link_directories(${RAYLIB_LIBRARY})

# Link the Raylib library to your project
target_link_libraries(${PROJECT_NAME} -static ${RAYLIB_LIBRARY})



