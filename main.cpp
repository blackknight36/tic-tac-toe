// This is a tic-tac-toe board.
// Michael Watters
// 11/20/04

#include <iostream>
#include <time.h>

#include "tictac.h"

extern bool winner;

int main() {

    srand( time(0) );

    int round_count = 0;
    int size = get_board_size();
    int max_rounds = size * size;

    do {
 
        draw_board();

        computer_move();
        
        draw_board();
        
        check_winner_horz();
        check_winner_vert();
        check_winner_diag();
        
        human_move();
        
        draw_board();
        
        round_count++;

        if (round_count == max_rounds) {
            std::cout << "No more moves.  The game is a tie." << std::endl;
            winner = true;
        }
        
    } while(true);
}
