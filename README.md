# Rush Hour Game

## Overview
"Rush Hour" is a basic 2D game developed in C++. The objective of the game is to navigate a taxi through a city, picking up and dropping off passengers within a set time limit.

## Files
The project consists of the following files:

- **CImg.h**: This file is part of the CImg Library, a C++ Template Image Processing Toolkit. It is used for handling image processing tasks in the game.
- **game.cpp**: The main source file for the game. It includes the game logic, state management, and interaction with the player.
- **util.cpp**: Contains utility functions used across the game.
- **util.h**: Header file for the utility functions declared in `util.cpp`.

## Getting Started

### Prerequisites
- A C++ compiler (e.g., GCC, Clang)
- Make sure you have the necessary libraries installed, including the CImg library.

### Compilation
To compile the game, use the following command:

```sh
g++ -o RushHour game.cpp util.cpp -lX11 -lpthread -lm
```
## Running the Game
After compilation, run the game using:

```sh
./RushHour
```

### Game Controls
+ Use the arrow keys to navigate the taxi.
+ Follow the on-screen instructions to pick up and drop off passengers.
### Author
Omer Nasir
