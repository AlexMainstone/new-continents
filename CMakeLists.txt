cmake_minimum_required(VERSION 3.0)

project(base-builder)

set(SOURCES
        src/Main.cpp
        src/Scenes/GameScene.cpp
    )

add_executable(base-builder ${SOURCES})

find_package(SFML 2 REQUIRED audio graphics window system)
target_include_directories(base-builder PRIVATE ${CMAKE_SOURCE_DIR}/include)