cmake_minimum_required(VERSION 3.28)

project(Aaron)

include(FetchContent)

set(RAYLIB_VERSION 4.2.0)

FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
    FIND_PACKAGE_ARGS ${RAYLIB_VERSION} EXACT
)

set(BUILD_EXAMPLES OFF CACHE INTERNAL "")
FetchContent_MakeAvailable(raylib)

set(
SOURCE_FILES

    src/main.cpp
    src/App.cpp
    src/Classes/Game.cpp
    src/Classes/Entity/Sprite.cpp
    src/Classes/Entity/Player.cpp
    src/Classes/Entity/Asteroid.cpp
    src/Classes/until.cpp
)

add_executable(Aaron ${SOURCE_FILES})
target_link_libraries(Aaron raylib)