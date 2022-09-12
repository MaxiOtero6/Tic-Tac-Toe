#include <iostream>
#include <string>

#include "tools.h"

bool validate_option(std::string option_str)
{
    std::string compatible_options[3] = {"1", "2"};

    for (int i = 0; i < 3; i++)
    {
        if (option_str == compatible_options[i])
        {
            return true;
        }
    }
    return false;
}

void ask_option(int &option)
{
    std::string option_str;
    do
    {
        std::cout << "\n\nHi!, which action do you want to do?:\n"
                    << "1 - Play Tic-Tac-Toe\n"
                    << "2 - Exit\n";
        std::getline(std::cin >> std::ws, option_str);
    } while (!validate_option(option_str));
    option = stoi(option_str);
}

void print_board(Board *board_pointer)
{

    // Prints board
    std::cout << "\n\n";

    std::cout << "   Board\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (j != 2)
            {
                std::cout << ' ' << board_pointer->token[i][j] << " |";
            }
            else if (j == 2)
            {
                std::cout << ' ' << board_pointer->token[i][j] << " \n";
            }
        }
    }
    std::cout << "\n";
}

void ask_icon(char &icon)
{
    std::string icon_str;

    do
    {
        std::cout << "Which icon do you use?: ";
        std::getline(std::cin >> std::ws, icon_str);
    } while (icon_str.length() > 1);

    icon = icon_str[0];
}

bool validate_position(std::string position_str, Board *board_pointer, int &row, int &position)
{
    std::string posible_positions[_POSITIONS_] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    for (int i = 0; i < _POSITIONS_; i++)
    {
        if (position_str == posible_positions[i])
        {
            position = stoi(position_str) - 1;
            while (position > 3)
            {
                position -= 3;
                row++;
            }
            if (board_pointer->token[row][position] == posible_positions[i][0]) // Cast pos_position into char
            {
                return true;
            }
        }
    }
    return false;
}

void ask_position(int &position, Board *board_pointer, int &row)
{
    std::string position_str;
    do
    {
        std::cout << "What position do you want to use?: ";
        std::getline(std::cin >> std::ws, position_str);
    } while (!validate_position(position_str, board_pointer, row, position));
}

bool row_check(Board *board_pointer, char icon)
{
    int icon_quantity = 0;
    for (int i = 0; i < 3; i++)
    {
        icon_quantity = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board_pointer->token[i][j] == icon)
            {
                icon_quantity++;
            }
        }
        if (icon_quantity == 3)
        {
            return true;
        }
    }
    return false;
}

bool column_check(Board *board_pointer, char icon)
{
    int icon_quantity = 0;
    for (int i = 0; i < 3; i++)
    {
        icon_quantity = 0;
        for (int j = 0; j < 3; j++)
        {
            if (board_pointer->token[j][i] == icon)
            {
                icon_quantity++;
            }
        }
        if (icon_quantity == 3)
        {
            return true;
        }
    }
    return false;
}

bool diagonal_check(Board *board_pointer, char icon)
{
    int icon_quantity = 0;
    for (int i = 0; i < 3; i++)
    {
        if (board_pointer->token[i][i] == icon)
        {
            icon_quantity++;
        }
    }

    if (icon_quantity == 3)
    {
        return true;
    }

    icon_quantity = 0;
    int i = 2, j = 0;
    while (i >= 0 && j < 3)
    {
        if (board_pointer->token[i][j] == icon)
        {
            icon_quantity++;
        }
        i--;
        j++;
    }

    if (icon_quantity == 3)
    {
        return true;
    }

    return false;
}

bool check_winner(Board *board_pointer, char icon)
{
    std::cout << icon << "\n";
    if (row_check(board_pointer, icon))
    {
        return true;
    }
    else if (column_check(board_pointer, icon))
    {
        return true;
    }
    else if (diagonal_check(board_pointer, icon))
    {
        return true;
    }
    return false;
}
