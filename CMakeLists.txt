cmake_minimum_required(VERSION 3.28)

project(Mouse_Cheese)

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

add_executable(Mouse_Cheese ${SOURCE_FILES})
target_link_libraries(Mouse_Cheese raylib)

if(WIN32)

    target_sources(Mouse_Cheese PRIVATE Assets/Windows/app.rc)
    target_link_options(Mouse_Cheese PRIVATE $<$<CONFIG:Release>:-mwindows>)
elseif(APPLE)

    target_link_options(Mouse_Cheese PRIVATE $<$<CONFIG:Release>:-MACOSX_BUNDLE>)
endif()

target_compile_definitions(Mouse_Cheese PUBLIC $<$<CONFIG:Debug>:DEBUG_ENABLED>)

if("${PLATFORM}" STREQUAL "Web")

    message(FATAL_ERROR "Do not build in this project in the Web as it doesn't work!")
endif()

if(APPLE)

    target_link_libraries(${PROJECT_NAME} "-framework IOKit")
    target_link_libraries(${PROJECT_NAME} "-framework Cocoa")
    target_link_libraries(${PROJECT_NAME} "-framework OpenGL")
endif()