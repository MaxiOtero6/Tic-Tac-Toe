#ifndef PLAYERS_H
#define PLAYERS_H

#include <string>
#include "tools.h"

struct Player
{
    std::string name;
    int score = 0;
    char icon;
};

struct Players
{
    Player player_1;
    Player player_2;
};

void input_players(Players *players_pointer);

void choose_position(Board *&board_pointer, char player_icon);

char select_icon(int turn, Players *players_pointer);

std::string select_winner(int turn, Players *players_pointer);

void print_scoreboard(Players *players_pointer);

#endif