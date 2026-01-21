cmake_minimum_required(VERSION 3.16)
project(card_battle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Source
add_library(card_battle_lib
    src/GameManager.cpp
    src/map/Lane.cpp
    src/map/MainBoard.cpp
    src/cards/Card.cpp
    src/characters/Character.cpp
    src/characters/Mage.cpp
    src/characters/Tank.cpp
)

target_include_directories(card_battle_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Executables
add_executable(card_battle_tests
    tests/main.cpp
)

target_link_libraries(card_battle_tests
    PRIVATE card_battle_lib
)
