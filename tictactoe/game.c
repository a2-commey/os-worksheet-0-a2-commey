#include <stdio.h>
#include "game.h"

// Fill the 3x3 board with spaces so the game starts empty
void init_board(char board[3][3]) {
    for (int r = 0; r < 3; r++) {       // loop through rows
        for (int c = 0; c < 3; c++) {   // loop through columns
            board[r][c] = ' ';          // set each cell to a space
        }
    }
}

// Print the board in a human-readable format
void print_board(char board[3][3]) {
    printf("\n");
    for (int r = 0; r < 3; r++) {
        // Print one row of the board
        printf(" %c | %c | %c\n", board[r][0], board[r][1], board[r][2]);

        // Print row separator except after last row
        if (r < 2)
            printf("---+---+---\n");
    }
    printf("\n");
}

// Put the player's symbol into the chosen cell
// This uses a POINTER to directly modify the cell's memory location
void make_move(char board[3][3], int row, int col, char player) {

    // Take the address of the selected cell in the 2D array
    char *cell = &board[row][col];

    // Only place symbol if the cell is currently empty
    if (*cell == ' ') {
        *cell = player;        // write the player's symbol to that memory address
    }
}

// Check all rows, columns, and diagonals to see if someone won
int check_winner(char board[3][3]) {

    // Check each row and column
    for (int i = 0; i < 3; i++) {

        // Check row i
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return 1;

        // Check column i
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return 1;
    }

    // Check the left-to-right diagonal
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return 1;

    // Check the right-to-left diagonal
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return 1;

    return 0;  // no winner found yet
}
