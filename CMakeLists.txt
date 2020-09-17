cmake_minimum_required(VERSION 3.0)
project(base-builder)

set (CMAKE_CXX_STANDARD 17)

set(SOURCES
    # Main loop
    src/Main.cpp

    # Maths
    src/Maths/Pathfinding.cpp

    # Scenes
    src/Scenes/GameScene.cpp

    # Resource Loading
    src/Resources/TileSet.cpp

    # Map Stuff
    src/World/MapGenerator.cpp
    src/World/Tile.cpp
    src/World/Chunk.cpp
    src/World/Map.cpp

    # Entities are Dynamic world features
    src/Entities/Entity.cpp
    src/Entities/Worker.cpp

    # Objects are static world features
    src/Objects/Object.cpp

    # Entities act Tasks on Objects
    src/Tasks/Task.cpp
    src/Tasks/DestroyTask.cpp

    # UI Elements
    src/Interface/GameInterface.cpp
    src/Interface/BuildMenu.cpp
    src/Interface/ActionMenu.cpp
    src/Interface/Button.cpp
    src/Interface/WordButton.cpp
    src/Interface/IconButton.cpp
    src/Interface/Text.cpp
    src/Interface/Cursor.cpp

    # Managers Manage
    src/Managers/TaskManager.cpp
    src/Managers/WorkerManager.cpp
    )


add_executable(base-builder ${SOURCES})

target_include_directories(base-builder PRIVATE ${CMAKE_SOURCE_DIR}/include /usr/include/python3.8/)
link_directories(/usr/lib/python3.8)

find_package(SFML 2.5 REQUIRED audio graphics window system)
find_package(ImGui-SFML REQUIRED)

target_link_libraries(base-builder
    python3.8 crypt pthread dl util m
    ImGui-SFML::ImGui-SFML
    sfml-audio sfml-graphics sfml-window sfml-system)