# SDL2 Game (not the definitive title)
This is a small project that may go nowhere.
The objective of this project is for me to practice C++ in a game development fashion.
The principal objectve is an object oriented implementation of SDL2.

# Actual objectives
- Primary objective is a 2d like platformer but the implementation will allow other 2d like games to be build with the core library.
- Implementation of rendering, sound and physics including water like 2d object.
- Reach a state where a simple demo may exist.

# Future objectives
- Implementation of 3d assets.
- Implementation 3d sound.

# Depedencies
This project was written in C++17.

- sdl2 2.28.5
- sdl2_image 2.8.1
- sdl2_ttf 2.20.2
- Compiled with gcc 13.2.0

# Build instructions
#### For MacOS / Linux : Install the libraries above with your prefered package manager.
#### For windows : You will need to download the libraries listed above and extract then at the root of this repository, otherwise same build instructions.
#### Then:
```bash
  make debug
```

The executable binary will be in the bin directory.

# Author(s)
[@IvoCostaCunha]https://github.com/IvoCostaCunha