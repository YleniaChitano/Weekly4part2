#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>


void printBoard(std::vector <int>& playerPos);
std::vector <int> move(std::vector <int>& playerPos);
void end();

int main()
{
    int loop = 0;

    std::vector <int> playerPos{ 0,0 };


    while ( loop == 0) {

        printBoard(playerPos);
        move(playerPos);

    }

    

}

void printBoard(std::vector <int>& playerPos) {


    char player = 'O'; // A symbol to show the player's position

    std::vector <std::vector <char>> board(10, std::vector<char>(10, ' ')); // A vector to store the content of the board

    for (unsigned int i = 0; i < board.size(); i++) {

        for (unsigned int j = 0; j < board[i].size(); j++) {

            if (i == 4 && j == 2) {

                board[i][j] = '/';
            }

            if (i == 6 && j == 8) {

                board[i][j] = '\\';
            }

            if (i == 9 && j == 7) {

                board[i][j] = 'G';
            }

            if (i == playerPos.at(0) && j == playerPos.at(1)) {

                board[i][j] = player;
            }

            if (playerPos.at(0) == 4 && playerPos.at(1) == 2) {
                playerPos.at(0) = (playerPos.at(0) + 1);
            }

            if (playerPos.at(0) == 6 && playerPos.at(1) == 8) {
                playerPos.at(0) = (playerPos.at(0) - 1);
            }

            if (playerPos.at(0) == 9 && playerPos.at(1) == 7) {

                end();
            }
            std::cout << board[i][j];

        }
        std::cout << std::endl;
    }
}

std::vector <int> move(std::vector <int>& playerPos) {
    char move;
    move = _getch();
    if (move == 'a' && playerPos.at(1) != 0) {
        playerPos.at(1) = (playerPos.at(1) - 1);

    }

    if (move == 'd' && playerPos.at(1) != 9) {
        playerPos.at(1) = (playerPos.at(1) + 1);
    }

    if (move == 'w' && playerPos.at(0) != 0) {
        playerPos.at(0) = (playerPos.at(0) - 1);
    }

    if (move == 's' && playerPos.at(0) != 9) {
        playerPos.at(0) = (playerPos.at(0) + 1);
    }


    return playerPos;
}

void end() {
    std::cout << "Game over!!!";
    exit(0);
}