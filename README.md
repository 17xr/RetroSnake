# Retro Snake Game
A redesigned Retro Snake game implemented in C++ with a visually appealing GUI. It is designed to be easy to understand and play, while providing an enjoyable retro gaming experience.

## Features
- **Classic Gameplay:** Navigate the snake around the screen to collect food and grow longer.
- **Beautiful GUI:** Retro-themed graphics with smooth animations and a user-friendly interface.
- **Simple Controls:** Use arrow keys or WASD keys to control the snake's movement.
- **Score Tracking:** Keep track of your score and try to beat it.

## Getting Started
### Prerequisites
To build and run the Retro Snake Game, you need:
- A C++ compiler (e.g., g++, clang++).
- CMake (for building the project)
- Raylib (for rendering the game).

### Installation
1. **Install Dependencies:**
- Check the official website for how to install [Raylib](https://www.raylib.com/#supported-platforms).
2. **Clone the Repository:**
```
git clone https://github.com/17xr/RetroSnake.git
cd cd retro-snake-game
```

### Building the Project
1. **Create a Build Directory:**
```
mkdir build
cd build
```
2. **Generate Build Files with CMake:**
```
cmake ..
```
3. **Compile the Project:**
```
make
```

## Run the game
Once the build process is complete, you can run the game with:
```
./retro_snake
```

## Gameplay
- **Objective:** Guide the snake to eat food and grow as long as possible without running into walls or itself.
- **Controls:** Use WASD keys to change the direction of the snake.

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
