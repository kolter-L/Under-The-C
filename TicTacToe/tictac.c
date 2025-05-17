#include <stdio.h>
#include <stdlib.h>
#include "minimax.h"
#include <stdbool.h>
#include <string.h>

// TODO:
    // IMPLEMENT DEPTH SO THAT IT WILL ALWAYS CHOOSE THE QUICKEST PATH TO WIN
    // ADD ALPHA-BETA PRUNING
    // MAKE ALL FUNCTIONS FLEXIBLE SO THAT THE BOARD SIZE CAN BE CHANGED

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

int* next_move(int x, int y, char board[x][y]) {
    int* res = malloc(2*sizeof(int));
    bool valid = false;

    while (!valid) {
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
        if (board[res[0]][res[1]] == ' ') {
            valid = true;
        }
        else {
            printf("YOU CANNOT MOVE HERE\n");
        }
    }
    return res;
}

int* machine_plays(int x, int y, char board[x][y]) {
    int* res = malloc(2*sizeof(int));
    int score = 2;

    for (int i=0; i<x; i++){
        for (int j=0; j<y; j++){
            if (board[i][j] == ' ') {
                char test_board[3][3]; 
                memcpy(test_board, board, sizeof(test_board));
                test_board[i][j] = 'O';
                int new_score = minimax(x, y, test_board, 0, true);

                if (new_score <= score) {
                    score = new_score;
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
    }
    return res;
}

int main() {
    int state = 2;
    
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };

    int index=0;
    while (state==2) {
        
        if (index%2==0){
            print_board(3, 3, board);
            printf("Your Turn\n");
            int* next = next_move(3, 3, board);
            board[next[0]][next[1]]='X';
        }
        else{
            int* next = machine_plays(3, 3, board);
            board[next[0]][next[1]]='O';
            printf("\n");
            printf("Machine's Move:\n");
        }
        state = game_state(3, 3, board);
        index++;
    }

    print_board(3, 3, board);
    if (state == 1){
        printf("X Wins");
    }
    else if (state == -1) {
        printf("O wins");
    }
    else if (state == 0) {
        printf("Tie");
    }
    return 0;
}