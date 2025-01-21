# so_long

## Project Description
**so_long** is a 2D game project created as part of the 42 curriculum. The goal is to implement a simple game where the player navigates through a map, collects items, and reaches an exit while avoiding obstacles. The project uses the **MinilibX** graphics library to create a basic graphical interface and focuses on handling game logic and user input.

## What I Did
In this project, I developed a 2D game with the following features:

### 1. **Map Parsing**
   - I created a parser that reads a map from a `.ber` file and stores it as a 2D array.
   - The map consists of different elements like walls, empty spaces, collectibles, the player’s starting position, and the exit point.
   - I ensured that the map adheres to certain constraints, such as having walls around the perimeter and that there is a valid exit and player position.

### 2. **Player Movement**
   - I implemented player movement with keyboard inputs (W, A, S, D) for up, left, down, and right.
   - The movement is restricted by walls (represented by `1` in the map).
   - The player’s position is updated in real-time, and the screen is refreshed to reflect changes in position.

### 3. **Game Logic**
   - I added the game’s main logic, which tracks the number of collectibles (represented by `C`) and checks whether the player has collected them all before reaching the exit (`E`).
   - Once the player collects all the items, the exit becomes accessible, and the game ends when the player reaches the exit.

### 4. **Graphics**
   - I used the MinilibX library to render the game’s graphical interface.
   - The player, collectibles, walls, and exit are displayed on the screen as images.
   - The game refreshes after each player movement to reflect the updated game state.

### 5. **Event Handling**
   - I used event listeners to capture player input and handle events like closing the game window or moving the player.
   - I ensured that the game loop continuously checks for events and updates the game state accordingly.

### 6. **Edge Case Handling**
   - I validated that the map files are correctly formatted and that there are no errors like missing walls or unconnected paths.
   - The game checks if the player has a valid path to the exit and does not allow the player to get stuck.

### Challenges and Solutions
- **Handling player movement:** One challenge was ensuring that the player could only move within the bounds of the map and avoid walls. I solved this by checking the player’s next position before allowing movement.
- **MinilibX integration:** The graphics library was new to me, so I had to learn how to use MinilibX functions for rendering images and creating windows. I referred to documentation and examples to integrate it successfully.
- **Input handling:** Capturing key events (W, A, S, D) for movement required learning how to work with event loops in MinilibX. I implemented a simple event system to handle user inputs and update the screen accordingly.

## Features
- Map reading and parsing from `.ber` files.
- Player movement with WASD controls.
- Collecting items and reaching the exit.
- Handling walls, obstacles, and valid movement paths.
- Game graphics rendered with MinilibX.

## Requirements
- **MinilibX** graphics library (provided by 42)
- A Linux system (or compatible environment)
- A C compiler (e.g., gcc)
- Make utility

## Installation
To set up and run the game on your local machine, follow these steps:

**Clone MinilibX** (if it's not already included in your project):

   If you don't have MinilibX as a submodule or separate folder, you can clone it directly from the 42 repository:
   ```bash
 git clone https://github.com/42Paris/minilibx-linux.git
cd minilibx-linux
make

1. **Clone the repository**:
   ```bash
   git clone https://github.com/AhmadSaadeh03/so_long.git
   cd so_long
   make
./so_long maps/map1.ber
