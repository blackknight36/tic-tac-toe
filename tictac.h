#ifndef __TICTAC_H_INCLUDED__ 
#define __TICTAC_H_INCLUDED__

int get_board_size();

void draw_board();

bool check_winner_horz();

bool check_winner_vert();

bool check_winner_diag();

void human_move();

void computer_move() ;

void zero_board();

#endif
