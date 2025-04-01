#include <stdio.h>
#include <stdlib.h>
#include "minimax.h"

/* Testing commit with new email */

void print_board(int x, int y, char board[x][y]){
    printf("-------------\n");
    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("-------------\n");
    }
}

int* next_move() {
    int* res = malloc(2*sizeof(int));
    res[0]=-3;
    res[1]=-3;

    while(!(res[0]>-1) || !(res[0]<3)) {
        printf("Enter Row: ");
        scanf("%d", &res[0]);
    }

    while(!(res[1]>-1) || !(res[1]<3)) {
        printf("Enter Col: ");
        scanf("%d", &res[1]);
    }

    return res;
}

int main() {
    int state = 0;
    
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int index=0;
    while (state==0 && index<10) {
        print_board(3, 3, board);
        
        if (index%2==0){
            printf("X Turn\n");
            int* next = next_move();
            board[next[0]][next[1]]='X';
        }
        else{
            printf("O Turn\n");
            int* next = next_move();
            board[next[0]][next[1]]='O';
        }
        state = game_state(3, 3, board);
        index++;
    }

    print_board(3, 3, board);
    if (state == 1){
        printf("X Wins");
    }
    else {
        printf("O wins");
    }
    return 0;
}