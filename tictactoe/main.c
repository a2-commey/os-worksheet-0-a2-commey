#include <stdio.h>
#include "game.h"

int main() {

    char board[3][3];   // 3x3 game board array

    // Fill the board with spaces so game starts empty
    init_board(board);

    char player = 'X';  // X always starts
    int row, col;       // user input values

    while (1) {

        // Show updated board after each move
        print_board(board);

        // Ask the current player which cell they want to play
        printf("Player %c, enter row and col (0-2): ", player);
        scanf("%d %d", &row, &col);

        // Place the symbol in the board (uses a pointer inside make_move)
        make_move(board, row, col, player);

        // Check if the move caused a win
        if (check_winner(board)) {
            print_board(board);        // show final board
            printf("Player %c wins!\n", player);
            break;                     // stop the game loop
        }

        // Switch turns: X → O, O → X
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}
