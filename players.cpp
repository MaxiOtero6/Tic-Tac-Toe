#include <iostream>
#include <string>

#include "players.h"
#include "tools.h"

void input_players(Players *players_pointer)
{

    // Ask the user the name of the players and which icon will they use

    std::cout << "Player 1: ";
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, players_pointer->player_1.name);
    ask_icon(players_pointer->player_1.icon);

    std::cout << "Player 2: ";
    std::cout << "Name: ";
    std::getline(std::cin >> std::ws, players_pointer->player_2.name);
    ask_icon(players_pointer->player_2.icon);
}

void choose_position(Board *&board_pointer, char player_icon)
{
    int position, row = 0;
    std::cout << player_icon << ": ";
    ask_position(position, board_pointer, row);

    board_pointer->token[row][position] = player_icon;
}

char select_icon(int turn, Players *players_pointer)
{
    char icon;
    if (turn % 2 != 0)
    {
        icon = players_pointer->player_1.icon;
    }
    else if (turn % 2 == 0)
    {
        icon = players_pointer->player_2.icon;
    }
    return icon;
}

std::string select_winner(int turn, Players *players_pointer)
{
    std::string winner;
    if (turn % 2 != 0)
    {
        winner = players_pointer->player_1.name;
        players_pointer->player_1.score++;
    }
    else if (turn % 2 == 0)
    {
        winner = players_pointer->player_2.name;
        players_pointer->player_2.score++;
    }
    return winner;
}

void print_scoreboard(Players *players_pointer)
{
    std::cout << players_pointer->player_1.name << ": " << players_pointer->player_1.score << " points\n";
    std::cout << players_pointer->player_2.name << ": " << players_pointer->player_2.score << " points\n";
}