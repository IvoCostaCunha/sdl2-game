# SDL2 Game (not the definitive title)

## Introduction
This is a small project that may go nowhere.
The objective of this project is for me to practice C++ in a game development fashion.
The principal objective is an OOP (Object-Oriented Paradigm) implementation of SDL2.

## Actual objectives
- Primary objective is a 2d like platformer, but the implementation should allow other 2d like games to be built with the core library.
- Implementation of rendering, sound and physics including an water-like 2d object.
- Reach a state where a simple demo may exist.

## Future objectives
- Implementation of 3d assets.
- Implementation 3d sound.

## Dependencies
This project is written in C++17.

- sdl2 2.28.5
- sdl2_image 2.8.1
- sdl2_ttf 2.20.2
- Compiled with gcc 13.2.0

## Build
#### For MacOS / Linux : Install the libraries above with your package manager.
#### For windows : You will need to download the libraries listed above and extract then at the root of this repository, otherwise same build instructions.
#### Then:
```bash
  make debug
```

The executable binary will be in the bin directory.
