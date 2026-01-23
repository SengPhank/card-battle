cmake_minimum_required(VERSION 3.16)
project(card-battle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Includes 
find_package(wxWidgets 3.2 REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Source
add_library(card_battle_lib
    # Boot
    src/boot/CardHandler.cpp
    src/boot/ui/GamePanel.cpp
    src/boot/ui/MainMenuPanel.cpp
    src/boot/ui/MainWindow.cpp
    src/boot/ui/SettingsPanel.cpp
    src/boot/ui/UIManager.cpp
    # Game Data
    src/game/MatchManager.cpp
    src/game/Lane.cpp
    src/game/MainBoard.cpp
    src/cards/Card.cpp
    src/characters/Character.cpp
    src/characters/Mage.cpp
    src/characters/Tank.cpp
)

target_include_directories(card_battle_lib
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/lib
)

# Executables
add_executable(card_battle
    tests/main.cpp
)

target_link_libraries(card_battle
    PRIVATE card_battle_lib
    ${wxWidgets_LIBRARIES}
)
