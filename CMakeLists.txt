cmake_minimum_required(VERSION 3.25)
set(CMAKE_CXX_STANDARD 23)
project(BallKiller3000)

set(BALL_KILLER_VERSION_MAJOR 0)
set(BALL_KILLER_VERSION_MINOR 3)
set(BALL_KILLER_VERSION_PATCH 0)

set(SOURCES
        src/main.cpp
        src/gameHandler/startGame.cpp
        src/data.h
        src/gameHandler/highScore.cpp
        src/gameHandler/levelUp.cpp
        src/utils/random.cpp
        src/balls.cpp
        src/enemy/initialise.cpp
        src/gui/gameElements.cpp
        src/gui/gameOverlay.cpp
        src/gui/pauseMenu.cpp
        src/gui/gameOverScreen.cpp
        src/gui/startScreen.cpp
        src/utils/checkCollision.cpp
        src/player/move.cpp
        src/enemy/move.cpp
        src/gui/resizeWindow.cpp
        src/utils/getNearest.cpp
)

#
if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_definitions(-DDEBUG)
endif ()


add_executable(${PROJECT_NAME} ${SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Determine the target platform
if (WIN32)
    set(SYSTEM_NAME "win")
elseif (EMSCRIPTEN)
    set(SYSTEM_NAME "html")
elseif (UNIX AND NOT APPLE)
    set(SYSTEM_NAME "linux")
elseif (APPLE)
    set(SYSTEM_NAME "macos")
else ()
    set(SYSTEM_NAME CMAKE_SYSTEM_NAME)
endif ()

# Get the commit hash from the command line
option(COMMIT_HASH "Commit hash" "")
if (COMMIT_HASH)
    set(COMMIT_HASH_STRING "-${COMMIT_HASH}")
else ()
    set(COMMIT_HASH_STRING "")
endif ()

# Create the version string with the system name
set(FULL_VERSION "${BALL_KILLER_VERSION_MAJOR}.${BALL_KILLER_VERSION_MINOR}.${BALL_KILLER_VERSION_PATCH}-${SYSTEM_NAME}${COMMIT_HASH_STRING}")

configure_file(src/version.h.in ${CMAKE_CURRENT_BINARY_DIR}/version.h @ONLY)

# Install Dependencies
# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.5.0
    )
    FetchContent_MakeAvailable(raylib)
endif ()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG v4.5.1
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif ()
target_link_libraries(${PROJECT_NAME} PUBLIC raylib raylib_cpp)


# Disable console (for windows)
if (CMAKE_BUILD_TYPE STREQUAL "Release")
    set_target_properties(${PROJECT_NAME} PROPERTIES WIN32_EXECUTABLE YES)
endif ()

# Web Configurations
if (${PLATFORM} STREQUAL "Web")
    # Tell Emscripten to build an example.html file.
    set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".html")
endif ()

if (EMSCRIPTEN)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
    set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so that you can directly open it.
endif ()

# fix missing DLL files
if (WIN32)
    if (NOT MSVC)
        set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ -static -pthread")
    endif ()
    if (MSVC)
        add_definitions(-DMSVC)
    endif ()
endif ()


# Checks if OSX and links appropriate frameworks (only required on MacOS)
if (APPLE)
    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif ()

# Install the file
install(TARGETS ${PROJECT_NAME}
        COMPONENT ${PROJECT_NAME}
        DESTINATION .)