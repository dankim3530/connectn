#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "game_play.h"
#include "board.h"
#include "win.h"
#include "input_validation.h"

/*
This program includes all the functions that are required to play the game.
*/

/*
Sets up the game by displaying the board and getting the player's pieces. Takes in the number of rows and columns, a blank character, the board
as a 2d array, the starting player's turn position and the player's pieces as parameters.
*/ 
void setup_game(int num_rows, int num_cols, char blank_char, char*** out_board, int* out_starting_player_turn, char* *out_player_pieces){
    char** board = make_board(num_rows, num_cols, blank_char);
    display_game_state(board, num_rows, num_cols);
    int player_turn = get_player_turn();
    char* player_pieces = get_player_pieces();
    *out_board = board;
    *out_starting_player_turn = player_turn;
    *out_player_pieces = player_pieces;

}

// Gets the players turn and returns 0. No parameters taken.
int get_player_turn(){
    return 0;
}

// Gets the player's pieces and returns them. No parameters taken.
char* get_player_pieces(){
    char* player_pieces = (char*)calloc(3, sizeof(char));
    strcpy(player_pieces, "XO");
    return player_pieces;
}

/*
Prompts the player to play their turn. Places piece down and updates the new board. Takes in the board, the number of rows and columns, a 
blank character, and the current player's piece as parameters.
*/
void cur_take_turn(char** board, int num_rows, int num_cols, char blank_char, char cur_player_piece){
    int row, col;
    get_valid_move(board, num_rows, num_cols, blank_char, &row, &col, 1);
    place_piece(cur_player_piece, board, row, col);
    display_game_state(board, num_rows, num_cols);
}


/*
Determines if a move is valid and within the boundaries. Takes in the board, the number of rows and columns, a blank character,
the row and column of the new piece as pointers and the number of arguments needed as parameters.
*/
void get_valid_move(char** board, int num_rows, int num_cols, char blank_char, int* row, int *col, int num_args_needed){
    int num_args_read;
    do{
        printf("Enter a column between 0 and %d to play in: ", num_cols - 1);
        num_args_read = scanf("%d", col);
    }while(!is_valid_move(num_args_read, board, num_rows, num_cols, blank_char, row, *col, num_args_needed));

}

/*
Checks if the move is on the board, provided with the right format, and if there is a free space for the move to take place.
Takes in the number of arguments read, the board, the numbers of rows and columns, a blank character, the new row and column, and the
number of arguments needed from the user as parameters.
*/
bool is_valid_move(int num_args_read, char** board, int num_rows, int num_cols, char blank_char, int *row, int col, int num_args_needed){

    bool val = false;
   
    if(!move_is_on_board(num_cols, col) && !isValidFormat(num_args_read, num_args_needed)){
        printf("yes");
    }
    if(!isValidFormat(num_args_read, num_args_needed) || !move_is_on_board(num_cols, col)) {
        return false;  
    }
    for(int i = num_rows - 1; i >= 0; i--){
        if(board[i][col] == blank_char){
            val = true;
            *row = i;
        }
        
        
    }
    return val;
}


/*
Announces the winner or if the game is a tie. Takes in the board, the amount of pieces in a row to win, the rows and columns, the 
current player, and the result as an integer as parameters.
*/
void announce_results(char** board, int amt_to_win, int rows, int cols, int cur_player_turn, int result){
    if(result == 0){
        if(cur_player_turn == 0){
            printf("Player 2 Won!\n"); 
        }else{
            printf("Player 1 Won!\n"); 
        }
    }else{
        printf("Tie game!\n");
    }
}

// Changes the turns alternating between the two players. Takes in the current player as a parameter.
void change_turns(int* cur_player_turn){
    *cur_player_turn = (*cur_player_turn + 1) % 2;
}


/* 
Allows the game to be played as long as there is no winner. Takes in the board, amount to win, the rows, columns, a blank character,
the starting player's turn and the player's pieces as parameters.
*/
void play_game(char** board, int amt_to_win, int rows, int cols, char blank_char, int starting_player_turn, char* player_pieces){
    int cond = 2;
    int cur_player_turn = starting_player_turn;
    while(cond == 2){
        cur_take_turn(board, rows, cols, blank_char, player_pieces[cur_player_turn]);
        change_turns(&cur_player_turn);
        cond = is_game_over(board, amt_to_win, rows, cols);
    }
    announce_results(board, amt_to_win, rows, cols, cur_player_turn, cond);

}

// Cleans up the board and frees the pieces. Takes in the board, the rows and columns and the player's pieces as parameters.
void clean_up(char** board, int rows, int cols, char* player_pieces){
    delete_board(board, rows, cols);
    free(player_pieces);
}