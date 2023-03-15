#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_play.h"

// Prompts the user for input and provides the dimensions and goals of the game.

/*
This function asks the user for the rows, columns and the number in a row to win for the game. Takes in argc and argv as parameters to check
the amount of arguments given by the user.
*/
int main(int argc, char** argv){

    int num_rows;
    int num_cols;
    int amt_to_win;
    char blank_char = '*';
    char** board;
    char* player_pieces;
    int player_turn;

    if(argc < 4){
        printf("Not enough arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }else if(argc > 5){
        printf("Too many arguments entered\nUsage connectn.out num_rows num_columns\nnumber_of_pieces_in_a_row_needed_to_win");
        exit(0);
    }
    num_rows = atoi(argv[1]);
    num_cols = atoi(argv[2]);
    amt_to_win = atoi(argv[3]); 
    

    

    



    setup_game(num_rows, num_cols, blank_char, &board, &player_turn, &player_pieces);
    play_game(board, amt_to_win, num_rows, num_cols, blank_char, player_turn, player_pieces);
    clean_up(board, num_rows, num_cols, player_pieces);
}





