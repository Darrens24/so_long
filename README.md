<p align="center">
    <img src="so_longm.png" alt="Badge Name">
</p>

# SO_LONG Project README

## Overview

The SO_LONG project is a classic 2D grid-based game, developed in C, as part of the 42 school curriculum. The game involves a player navigating through a map, collecting items, and avoiding or overcoming obstacles to reach the exit. This README outlines the project's structure, including the bonus features implemented.
I wrote it and tested it at school, with the Mac version of the minilibx. It might be different on Linux.

## Project Structure

### Core Components

- **Map Parsing:** Utilizes a custom parsing function to read and validate the game map provided in `.ber` format.
- **Player Movement:** Handles keyboard inputs to move the player character across the map.
- **Collision Detection:** Checks for collisions with walls, collectibles, and game-ending entities.
- **Collectibles:** Manages the collection of items required to open the exit.
- **Exit Mechanics:** Ensures the exit only becomes accessible after all collectibles are gathered.
- **Counting Moves:** Displays the number of moves made by the player.

### Bonus Features Implemented

- **Enemies:** Incorporates basic enemy characters.
- **Animations:** Integrates basic animations for player and enemy movements.
- **Score System:** Implements a scoring system based on moves made.

## Technologies & Methodologies

- **Language:** C
- **Graphics Library:** MiniLibX or equivalent, for window management and rendering.
- **Memory Management:** Efficient use of memory with proper allocation and deallocation practices.
- **Error Handling:** Robust error handling to ensure stability and reliability.

## Challenges & Learning Outcomes

- **Map Parsing Robustness:** Ensuring the game map is accurately parsed and validated posed significant challenges, especially with custom file formats.
- **Efficient Rendering:** Achieving smooth and efficient rendering of game elements without overloading the CPU.
- **Memory Leak Prevention:** Diligent management of memory allocation and freeing to prevent leaks.

## Installation & Execution

```bash
git clone [repository-url]
cd so_long
make
./so_long [map-file.ber]
