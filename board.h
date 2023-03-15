#ifndef BOARD_H
    #define BOARD_H
    #include <stdbool.h>    

    char** make_board(int num_rows, int num_cols, char blank_char);
    void display_game_state(char **board, int rows, int cols);
    bool is_between(int value, int min_val, int max_val);
    bool move_is_on_board(int num_cols, int col);
    void place_piece(char piece, char** board, int row, int col);
    void delete_board(char** board, int rows, int cols);

#endif