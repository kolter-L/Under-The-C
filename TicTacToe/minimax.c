#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "minimax.h"
#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

int minimax(int x, int y, char board[x][y], int depth, bool is_max) {
    // BASE CONDITION
    int state = game_state(x, y, board);
    int best_score = is_max ? -2 : 2;

    // ANYTHING OTHER THAN 2 IS AN END STATE
    if (state != 2) {
        return state;
    }

    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (board[i][j] == ' ') {
                char test_board[x][y];
                memcpy(test_board, board, sizeof(test_board));
                test_board[i][j] = is_max ? 'X' : 'O';

                int score = minimax(x, y, test_board, depth+1, !is_max);

                if (is_max) {
                    best_score = max(best_score, score);
                }
                else {
                    best_score = min(best_score, score);
                }
            }
        }
    }

    return best_score;
}

int game_state(int x, int y, char board[x][y]) {
    int state = 0;
    // ROWS AND COLS
    for (int i=0; i<3; i++) {
        if (board[i][0] != ' ' && board[i][0]==board[i][1] && board[i][1]==board[i][2]) {
            if (board[i][0]=='X') {
                state = 1;
            }
            else {
                state = -1;
            }
        }
        if (board[0][i] != ' ' && board[0][i]==board[1][i] && board[1][i]==board[2][i]) {
            if (board[0][i]=='X') {
                state = 1;
            }
            else {
                state = -1;
            }
        }
    }
    // DIAGONALS    
    if (board[0][0] != ' ' && board[0][0]==board[1][1] && board[1][1]==board[2][2]) {
        if (board[0][0]=='X') {
            state = 1;
        }
        else {
            state = -1;
        }
    }
    if (board[2][0] != ' ' && board[2][0]==board[1][1] && board[1][1]==board[0][2]) {
        if (board[2][0]=='X') {
            state = 1;
        }
        else {
            state = -1;
        }
    }

    //  CHECKING FOR TIED TERMINAL STATE
    for (int i=0; i<x; i++) {
        for (int j=0; j<y; j++) {
            if (board[i][j] == ' ' && state == 0) {
                state = 2;
            }
        }
    }

    return state;
}