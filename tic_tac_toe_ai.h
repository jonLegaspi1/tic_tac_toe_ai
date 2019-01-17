#ifndef TIC_TAC_H
#define TIC_TAC_H

void printBoard(char board[3][3]);
bool checkWin(char board[3][3], char turn);
bool validateEntry(int row, int col, char board[3][3]);
bool checkFull(char board[3][3]);
void resetBoard(char board[3][3]);
void doNothing(char b[3][3]);
char changeTurn(char t);
int evaulate(char board[3][3]);
int minimax(char board[3][3], int depth, bool isMax);

#endif