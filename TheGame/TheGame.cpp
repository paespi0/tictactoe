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
void printWinningMessage();

const int gridSize = 11;
char gridPositions[gridSize] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
char gridLabels[gridSize];
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

		int playerChoice;
		std::cin >> playerChoice;

		if (playerChoice > 0 && playerChoice < 10)
		{
			gridLabels[playerChoice] = currentPlayerMark;
		}
		else
		{
			std::cout << "That doesn't seem right! Try again.\n\n";
		}

		drawCurrentGameState();
		checkForWin();
		currentTurn++;
	}
}

void drawCurrentGameState()
{
	std::cout << "Player 1 [X] vs. Player 2 [O]\n\n";

	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[1] << " | " << gridLabels[2] << " | " << gridLabels[3] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[4] << " | " << gridLabels[5] << " | " << gridLabels[6] << " \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "    " << gridLabels[7] << " | " << gridLabels[8] << " | " << gridLabels[9] << " \n";
	std::cout << "      |   |   \n\n";
}

void resetGame()
{
	system("CLS");
	playerTurns = gridSize-1;
	currentTurn = 1;

	// Populate the grid spaces with numbers again
	for (int i = 0; i < gridSize; i++) {

		gridLabels[i] = gridPositions[i];
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
	if ((gridLabels[1] == gridLabels[2] == gridLabels[3]) ||
		(gridLabels[4] == gridLabels[5] == gridLabels[6]) ||
		(gridLabels[7] == gridLabels[8] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[4] == gridLabels[7]) ||
		(gridLabels[2] == gridLabels[5] == gridLabels[8]) ||
		(gridLabels[3] == gridLabels[6] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[5] == gridLabels[9]) ||
		(gridLabels[3] == gridLabels[5] == gridLabels[7]))
	{
		gameWon = true;
	}
	else
	{
		gameWon = false;
	}
}

void printWinningMessage() {

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
