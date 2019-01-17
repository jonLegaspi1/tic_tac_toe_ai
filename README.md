# tic_tac_toe_ai
A tic tac toe game that utilizes the minimax algorithm to simulate artificial intelligence

## How to compile and run

**MacOS/ Ubuntu / Windows 10 using mingw**: 
Open a terminal/bash window and change to a desirable directory to save the program

1. Clone the repository and change into its directory
```
git clone https://github.com/jonLegaspi1/tic_tac_toe_ai.git
cd tic_tac_toe_ai
```


2. Compile using gcc to create an executable
`g++ -o tictac tic_tac_ai.cpp tic_tac_methods.cpp`

3. Run the executable
`./tictac`

## Planned features to be implemented
1. Adding a menu for various options that player can choose. These would include: Difficulty setting, view running score against AI, etc.
2. Diffculty Setting: Before a game plays, player chooses 0-9 to determine how perfectly the AI plays, which would be giving a varying factor of randomness to the AI moves.
