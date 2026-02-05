# Card Battle
Enjoy a card-based game involving unique characters, entities, and instant spell cards to battle with other bots and opponents. 

## Recommendations
- Debian-based systems: Ubuntu 22.04 (Jammy) or Later (Ubuntu 24.04 Noble Recommended)
- C++17
- GCC 9+ or Clang 10+
- CMake 3.16+

## Installation Preperation
1. Make sure you've updated your system
```bash
sudo apt update
sudo apt upgrade
```

2. Install dependecies
```bash
sudo apt install cmake # Installs CMakeLists
sudo apt install build-essential # Installs Make, G++, GCC
sudo apt install libgtk-3-dev # Installs CMake pkg for GUIs
```

## wxWidget System-wide installation (OPTIONAL)
1. Installs wxWidget on your system. Recommended if you plan to modify and repeatedly build this project!
wxWidget Installation: [wxWidgets Installation Guide](hhttps://github.com/SengPhank/card-battle/blob/main/docs/wxWidgetsInstallation.md)

## Building the project
### If you installed wxWidget System wide:
1. Ensure you clone the repo using
```bash
git clone https://github.com/SengPhank/card-battle.git
cd card-battle
```
2. Build and run with Makefile
```bash
make devv
```
### If you did not install wxWidget:
1. Ensure you clone the repo and the wxWidget module using
```bash
git clone https://github.com/SengPhank/card-battle.git --recursive
cd card-battle
```

2. Build and run with Makefile
```bash
make run
```
