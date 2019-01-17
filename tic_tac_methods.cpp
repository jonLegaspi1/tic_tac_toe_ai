#include <iostream>		//std::cout
#include <string>
#include "tic_tac_toe_ai.h"
#include <algorithm> //std::max, std::min
using namespace std;

void printBoard(char b[3][3]) {
	//print board
	cout << "-----------------" << endl;
	cout << "|R\\C| 0 | 1 | 2 |" << endl;
	cout << "-----------------" << endl;

	cout << "| 0 |";
	//for loops used to print each element
	for (int i = 0; i < 3; i++) {
		cout << " " << b[0][i] << " |";
	}
	cout << "\n-----------------" << endl;
	cout << "| 1 |";
	for (int i = 0; i < 3; i++) {
		cout << " " << b[1][i] << " |";
	}
	cout << "\n-----------------" << endl;
	cout << "| 2 |";
	for (int i = 0; i < 3; i++) {
		cout << " " << b[2][i] << " |";
	}
	cout << "\n-----------------" << endl;
}
bool checkWin(char b[3][3], char turn) {
	//check diagonals if they are the same characters
	if (b[0][0] == turn && b[1][1] == turn && b[2][2] == turn) {
		cout << turn << " IS THE WINNER!!!" << endl;
		return true;
	}
	else if (b[2][0] == turn && b[1][1] == turn && b[0][2] == turn) {
		cout << turn << " IS THE WINNER!!!" << endl;
		return true;
	}

	for (int i = 0; i < 3; i++) {
		//check rows if they are same
		if (b[i][0] == turn && b[i][1] == turn && b[i][2] == turn) {
			cout << turn << " IS THE WINNER!!!" << endl;
			return true;
		}
		//check cols if they are the same
		else if (b[0][i] == turn && b[1][i] == turn && b[2][i] == turn) {
			cout << turn << " IS THE WINNER!!!" << endl;
			return true;
		}
	}
	return false;
}
bool validateEntry(int r, int c, char b[3][3]) {
	//make sure row and col are within specific range
	if (r < 0 | c < 0 | r > 2 | c > 2) {
		cout << "Invalid entry: try again." << endl;
		cout << "Row & column numbers must be either 0, 1, or 2." << endl;
		return false;
	}
	//check to see if row is already taken
	else if (b[r][c] != ' ') {
		cout << "That cell is already taken.\nPlease make another selection." << endl;
		return false;
	}
	else {
		cout << "Thank you for your selection." << endl;
		return true;
	}
}
bool checkFull(char b[3][3]) {
	//check each entry, if it is not full if there at least one char that is empty
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (b[i][j] == ' ') {
				return false;
			}
		}
	}
	//cout << "DRAW! NOBODY WINS!" << endl;
	return true;
}
//clear board
void resetBoard(char b[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			b[i][j] = { ' ' };
		}
	}
}
//method used for ternary operator
void doNothing(char b[3][3]) {
}
//method to change the turn, always switches
char changeTurn(char t) {
	if (t == 'X') {
		return 'O';
	}
	else
		return 'X';
}
int evaluate(char b[3][3]){
    for (int i = 0; i < 3; i++){
        if (b[i][0] == b[i][1] && b[i][1] == b[i][2]){
            if (b[i][0] == 'X')
                //probably use -10 for X
                return -10;
            else if (b[i][0] == 'O')
                return 10;
        }  
    }
    for (int j = 0; j < 3; j++){
        if (b[0][j] == b[1][j] && b[1][j] == b[2][j]){
            if (b[0][j] == 'X')
                //probably use -10 for X
                return -10;
            else if (b[0][j] == 'O')
                return 10;
        }
    }
	if (b[0][0] == b[1][1] && b[1][1] == b[2][2]){
        if (b[0][0] == 'X')
            return -10;
        else if (b[0][0] == 'O')
            return 10;
    }
    if (b[0][2] == b[1][1] && b[1][1] == b[2][0]){
        if (b[0][2] == 'X')
            return -10;
        else if (b[0][2] == 'O')
            return 10;
    }
    return 0;
}
int minimax(char b[3][3], int depth, bool isMax){
    int score = evaluate(b);

    if (score == 10)
        return score;
    if (score == -10)
        return score;
    if (checkFull(b) == true)
        return 0;
    if (isMax){
        int best = -1000;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (b[i][j] == ' '){
                    b[i][j] = 'O';
                    best = max(best, minimax(b, depth+1, !(isMax)));
                    b[i][j] = ' ';
                }
            }
        }
        return best;      
    }
    else{
        int best = 1000;

        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (b[i][j] == ' '){
                    b[i][j] = 'X';

                    best = min(best, minimax(b, depth+1, !(isMax)));

                    b[i][j] = ' ';
                }
            }
        }
        return best;
    }
}
