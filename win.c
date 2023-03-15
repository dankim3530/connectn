#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "win.h"
#define MIN(i, j) (((i) < (j)) ? (i) : (j))

//This program includes all the ways a player can win the game.


// Determines if there is a winner or if it is a tie. Takes in the board, the amount to win, the rows and the cols as parameters.
int is_game_over(char **board, int amt, int rows, int cols){
    if(win(board, amt, rows, cols)){
        return 0;
    }else if(tie(board, amt, rows, cols)){
        return 1;
    }else{
        return 2;
    }
}

// Checks if the board is empty. Takes in the board, the rows, and columns as parameters.
bool empty_board(char** board, int num_rows, int num_cols){
    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j < num_cols; j++){
            if(board[i][j] != '*'){
                return false;
                break;
            }
        }
    }
    return true;
}

// Checks if there is a winner horizontally. Takes in the board, the amt to win, the rows and the columns as parameters.
bool win_horz(char **board, int amt_to_win, int rows, int cols){
    int i, j, val, count, next_val;

    if(amt_to_win > cols){
        return false;
    }

    for(i = 0; i < rows; i++){
        val = board[i][0];
        count = 1;
        for(j = 0; j < cols; j++){
            next_val = board[i][j+1];
            if(next_val != '*'){
                if(val == next_val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                count = 1;
                val = next_val;    
            }
            if(count == amt_to_win){
                return true;
            }
        }
    }

    return false;
}




bool win_vert(char **board, int amt_to_win, int rows, int cols){
    int i, j, val, count, next_val;

    if(amt_to_win > cols){
        return false;
    }

    for(i = 0; i < cols; i++){
        val = board[0][i];
        count = 1;
        for(j = 0; j < rows - 1; j++){
            next_val = board[j+1][i];
            if(next_val != '*'){
                if(val == next_val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                count = 1;
                val = next_val;    
            }
            if(count == amt_to_win){
                return true;
            }
        }
    }

    return false;
}


// Checks if there is a winner diagonally left. Takes in the board, the amt to win, the rows and the columns as parameters.
bool left_diagonal_win(char **board, int amt, int rows, int cols){
    int i, j;
    if(amt > MIN(rows, cols)){
        return false;
    }

    int count = 1;

    for(i = 0; i < cols - amt + 1; i++){
        int row = 0;
        char val = board[0][i];
        for(j = 1; j < MIN(cols - i, rows); j++){
            char next_val = board[row + j][i + j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
            
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }

    for(i = 1; i < rows - amt + 1; i++){
        int col = 0;
        char val = board[i][col];
        for(j = 1; j < MIN(rows - i, cols); j++){
            char next_val = board[i + j][col + j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    return false;
}

// Checks if there is a winner diagonally right. Takes in the board, the amt to win, the rows and the columns as parameters.
bool right_diagonal_win(char **board, int amt, int rows, int cols){
    int i, j;
    if(amt > MIN(rows, cols)){
        return false;
    }
    for(i = amt - 1; i < cols; i++){
        int count = 1;
        int row = 0;
        char val = board[0][i];
        for(j = 1; j < MIN(i + 1, rows); j++){
            char next_val = board[row + j][i - j];
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    for(i = 0; i < rows - amt + 1; i++){
        int col = cols - 1;
        char val = board[i][col];
        for(j = 1; j < MIN(rows-i, cols); j++){
            char next_val = board[i + j][col - j];
            int count = 1;
            if(val != '*'){
                if(next_val == val){
                    count += 1;
                }else{
                    count = 1;
                    val = next_val;
                }
            }else{
                val = next_val;
                count = 1;
            }
            if(count == amt){
                return true;
            }
        }
    }
    return false;

}

/*
Checks if there is a winner diagonally and returns the two possible diagonal wins. 
Takes in the board, the amt to win, the rows and the columns as parameters.
*/
bool win_diagonally(char **board, int amt, int rows, int cols){
    return (left_diagonal_win(board, amt, rows, cols) || right_diagonal_win(board, amt, rows, cols));
}

// Checks if there is a winner in any of the possible ways. Takes in the board, the amt to win, the rows and the columns as parameters.
bool win(char **board, int amt, int rows, int cols){
    return !empty_board(board, rows, cols) && ((win_horz(board, amt, rows, cols)) || 
            (win_vert(board, amt, rows, cols)) || 
            (win_diagonally(board, amt, rows, cols)));
}

//Checks if the game is a tie. Takes in the board, the amt to win, the rows and the columns as parameters.
bool tie(char **board, int amt, int rows, int cols){
    int i, j;
    for(i = 0; i < rows; i++){
        for(j = 0; j < cols; j++){
            if(board[i][j] == '*'){
                return false;
            }
        }
    }

    return true;
}