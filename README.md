# Sorting Visualizer

A sorting algorithm visualizer written in C with Raylib. Intended to be used as a way to learn and visualize how different sorting algorithms work. 

## Cloning 

This project has a dependency (Raylib), and uses git submodules. To properly clone the repository use this command: git clone --recursive https://github.com/JonathanRamos2002/sort-visualizer.git

If you cloned without the --recursive flag, initialize the submodule with the following command: git submodule update --init --recursive

## Dependency

After cloning build raylib to ensure the library is readily avialable with the following commands. 

1. cd raylib/src

2. make

3. cd ../..

## Build

1. Compile using the Makefile, the command "make" will compile the project properly.

2. Run the executable with the command "make run".

3. Clean up with the command "make clean"
