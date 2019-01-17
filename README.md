# tic_tac_toe_ai
A tic tac toe game that utilizes the minimax algorithm to simulate artificial intelligence.
The minimax algorithm is a backtracking algorithm used in game theory to find the optimal move a player should make. This assumes that the other player also plays optimally. In a game of two players, one is a "maximizer" and the other is a "minimizer". The maximizer will try to achieve the highest possible score, and the minimizer the lowest possible score. This game assumes has the AI as the maximizer and the player (you) as the minimizer. When a player makes a move, there are several paths that the game can follow in. This is best represented through a perfect binary tree. The final children of the bottom nodes have a value assigned to them. Since there are only three possible outcomes to this game (AI win, player win, draw), the values of these nodes have a +10(AI win), -10(player win), and 0 (draw). The program goes through each possible scenario, and will choose spots based on the greatest score. If it detects a +10 scenario, it will choose that spot. If it is deciding between a -10 or 0 scenario, it will choose the best possible outcome, which is drawing.
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

**Windows using Visual Studio** 
1. Create a new empty C++ project.
2. Download and add these as source files
3. Run project (uncomment system("pause") if you want do not want the console to close)

## Planned features to be implemented
1. Adding a menu for various options that player can choose. These would include: Difficulty setting, view running score against AI, etc.
2. Creating a smarter AI by considering the depth of the moves that would be necessary to achieve victory. If victory can be accomplished within a single turn, compared to two or three, than the AI should choose the quickest victory.
2. Diffculty Setting: Before a game plays, player chooses 0-9 to determine how perfectly the AI plays, which would be giving a varying factor of randomness to the AI moves.
3. Porting code to utilize WebAssembly so that anyone can run the program through an HTML page (where it also interacts with JavaScript). 
