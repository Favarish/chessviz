#ifndef _MOVING_H
#define _MOVING_H

extern char chess_field[9][9];
extern int flag;

int friend_or_foe(int position2_1, int position2_2);
void moving_a_shape(int i, int j, int position2_1, int position2_2);
int moving_pawnsB(int i, int j, int position2_1, int position2_2);
int moving_pawnsW(int i, int j, int position2_1, int position2_2);
int moving_rook(int i, int j, int position2_1, int position2_2);
int moving_knight(int i, int j, int position2_1, int position2_2);
int moving_bishop(int i, int j, int position2_1, int position2_2);
int moving_king(int i, int j, int position2_1, int position2_2);
int moving_queen(int i, int j, int position2_1, int position2_2);
int correct_input(int i, int j, int position2_1, int position2_2);
int win();

#endif
