# Casino Game Documentation

## Overview

This C++ program implements a simple casino game where players can bet on numbers between 1 and 10. The game allows players to deposit an initial amount, place bets, and potentially win or lose money based on their guesses.

## Functions

### `void drawLine(int n, char c)`

Draws a line of specified length using a given character.

- Parameters:
    - `n`: The length of the line to draw.
    - `c`: The character to use for drawing the line.

### `void displayRules()`

Displays the rules of the game to the player.

### `int getValidInput(int min, int max, const std::string& prompt)`

Prompts the user for input and validates it within a specified range.

- Parameters:
    - `min`: The minimum acceptable value.
    - `max`: The maximum acceptable value.
    - `prompt`: The message to display when asking for input.
- Returns: A valid integer input within the specified range.

### `int main()`

The main function that runs the game loop.

## Game Flow

1. The game starts by displaying a welcome message and prompting the player for their name and initial deposit.
2. The main game loop begins, which continues until the player chooses to stop or runs out of money.
3. In each round:
    - The rules are displayed.
    - The player's current balance is shown.
    - The player is prompted to place a bet.
    - A random winning number is generated.
    - The player guesses a number.
    - The result is calculated and displayed.
    - The player's balance is updated.
4. After each round, the player is asked if they want to continue playing.
5. When the game ends, the final balance is displayed.

## Key Features

- Input validation to ensure all user inputs are within acceptable ranges.
- Use of C++11 random number generation for better randomness.
- Clear display of game rules and current status.
- Ability to play multiple rounds until the player chooses to stop or runs out of money.

## Usage

1. Compile the program using a C++11 (or later) compatible compiler.
2. Run the executable.
3. Follow the on-screen prompts to play the game.

## Notes

- The game uses `system("cls")` to clear the screen, which is not portable across all systems. For cross-platform compatibility, consider replacing this with a more universal screen-clearing method.
- The random number generator is seeded with a device-based seed, ensuring different sequences each time the program is run.

## Potential Enhancements

1. Implement a high score system.
2. Add different betting options or game modes.
3. Improve the user interface with more graphical elements.
4. Add error handling for potential exceptions.
5. Implement a save/load feature for player progress.