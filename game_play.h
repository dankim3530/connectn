#ifndef GAME_PLAY_H
    #define GAME_PLAY_H
    #include <stdbool.h>    

    void setup_game(int num_rows, int num_cols, char blank_char, char*** out_board, int* out_starting_player_turn, char** out_player_pieces);
    int get_player_turn();
    char* get_player_pieces();
    void cur_take_turn(char** board, int num_rows, int num_cols, char blank_char, char cur_player_piece);
    void get_valid_move(char** board, int num_rows, int num_cols, char blank_char, int* row, int *col, int num_args_needed);
    bool is_valid_move(int num_args_read, char** board, int num_rows, int num_cols, char blank_char, int *row, int col, int num_args_needed);
    void announce_results(char** board, int amt_to_win, int rows, int cols, int cur_player_turn, int result);
    void change_turns(int* cur_player_turn);
    void play_game(char** board, int amt_to_win, int rows, int cols, char blank_char, int starting_player_turn, char* player_pieces);
    void clean_up(char** board, int rows, int cols, char* player_pieces);

#endif