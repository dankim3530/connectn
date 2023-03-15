#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "board.h"
// This c.file includes all things that surround the board of the game.

/*
Outlines an empty board filled with asterisks to cover up the empty spaces. Takes in the number of rows and columns of the board and 
the blank character '*' as parameters.
*/
char** make_board(int num_rows, int num_cols, char blank_char){
    int i, j;
    char **board = (char**)calloc(num_rows, sizeof(char*));
    for(i = 0; i < num_rows; i++){
        board[i] = (char*)calloc(num_cols, sizeof(char));
        for(j = 0; j < num_cols; j++){
            board[i][j] = blank_char;
        }
    }
    
    return board;
}


/*
Prints out the board using an asterisk for the empty spaces. Takes in a 2d array, number of rows, 
and number of columns as parameters.
*/
void display_game_state(char **board, int rows, int cols){
    int i, j;
    
    for(i = rows - 1; i >= 0; i--){
        printf("%d", i);
        for(j = 0; j < cols; j++){
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }
    printf(" ");
    for(i = 0; i < cols; i++){
        printf("%d ", i);
    }
    printf("\n");
    

}

/*
Replaces the asterisks with the user-given move. Takes in the player piece, the board as a 2d array,
and the number of rows and columns as parameters.
*/
void place_piece(char piece, char** board, int row, int col){
    board[row][col] = piece;
}

// Checks if a value is between two values. Takes in the value as well as the upper and lower bound values as parameters.
bool is_between(int value, int min_val, int max_val){
    return value >= min_val && value <= max_val;
}

// Uses the in_between function to determine if the move desired is on the board. Takes in the number of columns and the column desired as parameters.
bool move_is_on_board(int num_cols, int col){
    return is_between(col, 0, num_cols - 1);
}

// Deletes the board. Takes in the board and the number of rows and columns as parameters.
void delete_board(char** board, int rows, int cols){
    for(int i = 0; i < rows; i++){
        free(board[i]);
    }
    free(board);
}
