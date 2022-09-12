#ifndef TOOLS_H
#define TOOLS_H

const std::string SPACES = "            ";
const int _POSITIONS_ = 9;

struct Board
{

    char token[3][3] = {{'1', '2', '3'},
                        {'4', '5', '6'},
                        {'7', '8', '9'}};
};

bool validate_option(std::string option_str);

void ask_option(int &option);

void print_board(Board *board_pointer);

void ask_icon(char &icon);

bool validate_position(std::string position_str, Board *board_pointer, int &row, int &position);

void ask_position(int &position, Board *board_pointer, int &row);

bool row_check(Board *board_pointer, char icon);

bool column_check(Board *board_pointer, char icon);

bool diagonal_check(Board *board_pointer, char icon);

bool check_winner(Board *board_pointer, char icon);

#endif
