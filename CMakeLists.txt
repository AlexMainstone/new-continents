cmake_minimum_required(VERSION 3.0)
project(base-builder)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/Main.cpp

    src/Scenes/GameScene.cpp

    src/Resources/TileSet.cpp

    src/World/MapGenerator.cpp
    src/World/Tile.cpp
    src/World/Chunk.cpp
    src/World/Map.cpp

    src/Entities/Entity.cpp
    src/Entities/Player.cpp
    )

find_package(SFML 2.5 REQUIRED audio graphics window system)

add_executable(base-builder ${SOURCES})
target_include_directories(base-builder PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(base-builder sfml-audio sfml-graphics sfml-window sfml-system)