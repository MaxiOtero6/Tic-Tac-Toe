#include <iostream>
#include <string>
#include "tools.h"
#include "players.h"

int main()
{
    bool winner = false;
    int turn, option = 0;
    char icon;
    Players *players_pointer = new Players;
    Board *board_pointer;

    input_players(players_pointer);
    while (option != 2)
    {
        ask_option(option);

        switch (option)
        {
            case 1:
                turn = 0;
                board_pointer = new Board;
                do
                {
                    print_board(board_pointer);
                    turn++;
                    icon = select_icon(turn, players_pointer);
                    choose_position(board_pointer, icon);

                    winner = check_winner(board_pointer, icon);
                } while (!winner && turn < 9);

                if (winner)
                {
                    print_board(board_pointer);
                    std::cout << "Congratulations " << select_winner(turn, players_pointer) << " wins!!\n";
                }
                print_scoreboard(players_pointer);
                break;

            case 2:
                std::cout << "Thanks for playing!\n";
                delete players_pointer;
                delete board_pointer;
                break;
        }
    }
}