#ifndef MINIMAX_H
#define MINIMAX_H
#include <stdbool.h>

int game_state(int x, int y, char board[3][3]);

int minimax(int x, int y, char board[x][y], int depth, bool is_max);

#endif