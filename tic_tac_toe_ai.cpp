#include <iostream>
#include <string>
#include "tic_tac_toe_ai.h"
using namespace std;
struct Move 
{ 
    int row, col; 
}; 
Move findBestMove(char board[3][3]);

Move findBestMove(char b[3][3]){
	int bestVal = -1000;
	Move bestMove;
	bestMove.row = -1;
	bestMove.col = -1;

	for (int i = 0; i<3; i++){
		for (int j = 0; j<3; j++){
			if (b[i][j] == ' '){
				b[i][j] = 'O';

				int moveVal = minimax(b, 0, false);
				cout << "Moveval1: " << moveVal << endl;
				b[i][j] = ' ';

				if (moveVal > bestVal){
					bestMove.row = i;
					bestMove.col = j;
					bestVal = moveVal;
					cout << "Moveval2: " << moveVal << endl;
				}
			}
		}
	}
	cout << "Best val" << bestVal << endl;
	return bestMove;
}
int main() {
	//default variables and inits
	char cont = 'Y';
	char t = 'X';
	int row,
		col;
	char board[3][3];
	resetBoard(board);
	//start game as true
	bool newGame = true;
	do {
		//print new board if it is a new game
		cout << (newGame ? "New Game: X goes first.\n" : "") << endl;
		(newGame ? printBoard(board) : doNothing(board));
		newGame = false;

		if (t == 'X'){
			cout << t << "'s turn." << endl;
			cout << "Where do you want your " << t << " placed?" << endl;
			cout << "Please enter row and column number separated by a space." << endl;

			cin >> row >> col;
			cout << "You have entered row #" << row << endl;
			cout << "          and column #" << col << endl;

			//if it is a valid entry, change turn and check if winner or if full
			if (validateEntry(row, col, board)) {
				//store new value
				board[row][col] = t;
				//methods execute, if they are false, change the turn
				if (!checkWin(board, t) && !checkFull(board)) {
					t = changeTurn(t);	
				}
				else {
					//handles if user wants to play again
					printBoard(board);
					cout << "Another game? Enter Y or y for yes." << endl;
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						resetBoard(board);
						newGame = true;
					}
					
				}
			}
		}
		if (t == 'O'){
				Move bestMove = findBestMove(board);
				cout << "Best move is" << bestMove.row << bestMove.col << endl;
				board[bestMove.row][bestMove.col] = 'O';
				if (!checkWin(board, t) && !checkFull(board)) {
					t = changeTurn(t);	
				}
				else {
					//handles if user wants to play again
					printBoard(board);
					cout << "Another game? Enter Y or y for yes." << endl;
					cin >> cont;
					if (cont == 'Y' || cont == 'y') {
						resetBoard(board);
						newGame = true;
					}		
				}
			}
			//print board before looping
			printBoard(board);
	} while (cont == 'Y' || cont == 'y');
	cout << "\nThank you for playing!" << endl;
	//system("pause");
	return 0;
}