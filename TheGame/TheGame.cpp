// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

void playGame();
void printIntro();
void printInstructions();
void drawCurrentGameState();

const int gridSize = 10;
char gridNumbers[gridSize];

int main()
{
	playGame();
}

void printIntro()
{
	std::cout << "Let's play Tic Tac Toe!\nGet three in a row vertically, horizontally or diagonally to win.\n\n";
}

void printInstructions()
{

	std::cout << "Type a number on the grid and press \'Enter\' to place your mark there.\n\n";
}

void playGame()
{
}

void drawCurrentGameState()
{
	std::cout << "Player 1 [X] vs. Player 2 [O]\n\n";

	std::cout << "      |   |   \n";
	std::cout << "    " << gridNumbers[1] << " | " << gridNumbers[2] << " | " << gridNumbers[3] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridNumbers[4] << " | " << gridNumbers[5] << " | " << gridNumbers[6] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridNumbers[7] << " | " << gridNumbers[8] << " | " << gridNumbers[9] << " \n";
	std::cout << "      |   |   \n\n";
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
