#include <stdio.h>
#include <stdlib.h>
#include "minimax.h"

typedef struct {
    int row;
    int col;
} Move;

Move available_moves[9];
int count = 0;

void find_available_moves(int x, int y, char board[3][3]) {
    for (int i=0; i<y; i++) {
        for (int j=0; j<x; j++) {
            if (board[i][j]==' ') {
                available_moves[count].row=i;
                available_moves[count].col=j;
                count++;
            }
        }
    }
    for (int x=0; x<count; x++){
        printf("Available Move %d\n", x);
        printf("row: %d\n", available_moves[x].row);
        printf("col: %d\n", available_moves[x].col);
    }
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
    return state;
}