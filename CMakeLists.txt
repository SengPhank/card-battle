cmake_minimum_required(VERSION 3.16)
project(card-battle LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Includes 
find_package(wxWidgets 3.2 REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})

# Add all Game Cards
file(GLOB CARD_SOURCES
    src/cards/entity/*.cpp
    src/cards/instant/*.cpp
)
# Add all Characters
file(GLOB CHARACTER_SOURCES
    src/characters/heroes/*.cpp
)

# Source
add_library(card_battle_lib
    # Boot
    src/boot/ui/MainWindow.cpp
    src/boot/CardManager.cpp
    src/boot/CharacterManager.cpp
    # UI Handling
    src/ui/GamePanel.cpp
    src/ui/GamePanelHelper.cpp
    src/ui/MainMenuPanel.cpp
    src/ui/SettingsPanel.cpp
    # Game Data
    src/game/MatchManager.cpp
    src/game/Lane.cpp
    src/game/MainBoard.cpp
    # AI Data
    src/bots/BasicBot.cpp
    # Cards
    src/cards/Card.cpp
    src/cards/EntityCard.cpp
    src/cards/InstantCard.cpp
    ${CARD_SOURCES}
    # Characters
    src/characters/Character.cpp
    ${CHARACTER_SOURCES}
    
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
