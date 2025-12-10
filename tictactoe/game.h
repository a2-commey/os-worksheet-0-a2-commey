#ifndef GAME_H
#define GAME_H

// Sets every cell in the 3x3 board to a space character
void init_board(char board[3][3]);

// Prints the board in a tic-tac-toe layout
void print_board(char board[3][3]);

// Returns 1 if someone has won, otherwise returns 0
int check_winner(char board[3][3]);

// Places the player's symbol in the chosen cell using a pointer
void make_move(char board[3][3], int row, int col, char player);

#endif
