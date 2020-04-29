// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>

void playGame();
void printIntro();
void printInstructions();
void drawCurrentGameState();
void resetGame();
void askToPlayAgain();
void checkForWin();

const int gridSize = 10;
char gridNumbers[gridSize];
bool gameWon;
int playerTurns;
int currentTurn;

int main()
{
	playGame();
	askToPlayAgain();
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
	resetGame();
	printIntro();
	printInstructions();
	drawCurrentGameState();

	while (currentTurn < playerTurns && gameWon == false)
	{
		char currentPlayerMark;
		if (currentTurn % 2 == 1)
		{
			currentPlayerMark = 'X';
			std::cout << "> Player 1's turn [X]\n";
		}
		else
		{
			currentPlayerMark = 'O';
			std::cout << "> Player 2's turn [O]\n";
		}



		drawCurrentGameState();
		//checkForWin();
		currentTurn++;
	}
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

void resetGame()
{
	system("CLS");
	playerTurns = gridSize;
	currentTurn = 1;

	// Populate the grid spaces with numbers again
	for (int i = 0; i < gridSize; i++) {

		gridNumbers[i] = '%c', (char)i;
	}
}

void askToPlayAgain()
{
	char playerAnswer;
	std::cout << "Do you want to play again? Y/N...\n";
	std::cin >> playerAnswer;

	if (playerAnswer == 'y' || playerAnswer == 'Y') {
		playGame();
	}
	else {
		system("CLS");
	}
}

void checkForWin()
{
	if ((gridNumbers[1] == gridNumbers[2] == gridNumbers[3]) ||
		(gridNumbers[4] == gridNumbers[5] == gridNumbers[6]) ||
		(gridNumbers[7] == gridNumbers[8] == gridNumbers[9]) ||
		(gridNumbers[1] == gridNumbers[4] == gridNumbers[7]) ||
		(gridNumbers[2] == gridNumbers[5] == gridNumbers[8]) ||
		(gridNumbers[3] == gridNumbers[6] == gridNumbers[9]) ||
		(gridNumbers[1] == gridNumbers[5] == gridNumbers[9]) ||
		(gridNumbers[3] == gridNumbers[5] == gridNumbers[7]))
	{
		gameWon = true;
	}
	else
	{
		gameWon = false;
	}
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
