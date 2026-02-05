# wxWidget System-wide Installation Guide

## Linux/macOS Installation Guide
Make sure you *install all dependecies* before continuing
```bash
sudo apt update
sudo apt upgrade
sudo apt install build-essential # G++, Gcc, Installation
sudo apt install bzip2 # .bz2 extraction
sudo apt install cmake # CMakeLists
sudo apt install libgtk-3-dev # CMake pkg
```
1. Navigate to [wxWidgets Downloads](https://wxwidgets.org/downloads/) then look for the latest stable release, and download the source file **Source for Linux, macOS, etc**. (At the time of writing, the latest stable release is: **Latest Stable Release: 3.2.9**)
 
2. Find the *.bz2* file *wxWidgets-3.2.9.tar.bz2* on your machine and uncompress it using (Name may change depending on version)
```bash
cd ~/Downloads # Path to where the file went
tar -xjf wxWidgets-3.2.9.tar.bz2 # Requires bzip2 installed
cd wxWidgets-3.2.9
```

3. Build the wxWidget project using their respective CMakeLists
```bash
mkdir build-cmake
cd build-cmake
cmake .. -DwxBUILD_SHARED=OFF -DwxBUILD_GUI=ON # Build wxWidget v3.2.8
make -j$(nproc)
sudo make install # Installs system-wide
```

Don't forget to *head back to the root of the folder* **card-battle** before continuing with the next steps!


