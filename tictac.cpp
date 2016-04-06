#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>

#include "tictac.h"

const int row_max = 6, col_max = 6;
int board[row_max][col_max];
bool winner = false;

unsigned int size;

int get_board_size() {
    std::string message = "Number of rows? (Max 6) ";
    std::cout << message;
    std::cin >> size;
    if (size > row_max or size < 3 ) {
        printf("Invalid size entered.\n");
        get_board_size();
    }
    return size;
}

void draw_board() {
    system("clear");

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            
            switch (board[i][j]) {
                case 0: std::cout << "_" << "\t"; break;
                case 1: std::cout << "O" << "\t"; break;
                case 2: std::cout << "X" << "\t"; break;
            }
            
        }
        
        std::cout << std::endl;
    }
}

void play_again() {
    char response;
    
    std::cout << "Play again?";
    std::cin >> response;
    
    response = std::tolower(response);
    
    if (response ==  'n') {
        exit(0);
    }
    else {
        zero_board();
        get_board_size();
        draw_board();
    }
}

bool check_winner_horz() {
    for (int i = 0; i < size; i++) {
        int human_count = 0;
        int comp_count = 0;
        for (int j = 0; j < size; j++) {
            if (board[i][j] == 1)
                human_count++;
            if (board[i][j] == 2)
                comp_count++;
            if (human_count == size) {
                std::cout << "You win!" << std::endl;
                
                play_again();
                winner = 1;
            }
            if (comp_count == size) {
                std::cout << "Computer wins!" << std::endl;
                play_again();
                winner = 1;
            }
        }
    }
    return winner;
}

bool check_winner_vert() {
    // Check the columns for a winner.
    for (int j = 0; j < size; j++) {

        int human_count = 0;
        int comp_count = 0;
        char playagain;

        for (int i = 0; i < size; i++) {
            if (board[i][j] == 1)
                human_count++;
            if (board[i][j] == 2)
                comp_count++;
            if (human_count == size) {
                std::cout << "You win!" << std::endl;
                play_again();
            }

            if (comp_count == size) {
                std::cout << "Computer wins!" << std::endl;
                std::cout << "Play again?";
                std::cin >> playagain;
                
                playagain = std::tolower(playagain);

                if (playagain ==  'n') {
                    exit(0);
                }
            }
            }
        }
    return winner;
}

bool check_winner_diag() {
    
    int j = 0;
    int human_count = 0;
    int comp_count = 0;
    
    for (int i = 0; i < size; i++) {
        if (board[i][j] == 1)
            human_count++;
        if (board[i][j] == 2)
            comp_count++ ;
        if (human_count == size) {
            std::cout << "You win!" << std::endl;
            winner = 1;
        }
        if (comp_count == size) {
            std::cout << "Computer wins!" << std::endl;
            winner = 1;
        }
        j++;
    }
    
    j = size;
    human_count = 0;
    comp_count = 0;
    
    for (int i = size; i > 0; i--) {
        if (board[i][j] == 1)
            human_count++;
        if (board[i][j] == 2)
            comp_count++;
        if (human_count == size) {
            std::cout << "You win!" <<std::endl;
            winner = 1;
        }
        if (comp_count == size) {
            std::cout << "Computer wins!" << std::endl;
            winner = 1;
        }
        
    }
    return winner;
}

void human_move() {
    int row, col;
    std::cout << "Enter coordinates of your move: " << std::endl;
    std::cin >> row >> col;
    
    if ( (board[row][col] == 1) || (board[row][col] == 2) ) {
        std::cout << "That space is already full.\n";
        human_move();
    }
    else {
        board[row][col] = 1;
    }
}

void computer_move() {
    int row, col;

    row = rand() %size;
    col = rand() %size;

    if ( (board[row][col] == 1) || (board[row][col] == 2) ) {
        computer_move();
    }
    else {
        board[row][col] = 2;
    }
}

void zero_board() {
    for(int i = 0; i < row_max; i++)
        for (int j = 0; j < col_max; j++)
            board[i][j] = 0;
}

