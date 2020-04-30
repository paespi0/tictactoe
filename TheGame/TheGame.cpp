// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

#include <iostream>
#include <stdlib.h>
#include <conio.h>

void playGame();
void printIntro();
void printInstructions();
void drawCurrentGameState();
void setUpGame();
void askToPlayAgain();
void checkForWin();
void printWinningMessage();
void showMenu();
void showScoreboard();
void showCredits();

const int gridSize = 11;
char gridPositions[gridSize] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0' };
char gridLabels[gridSize];
bool gameWon;
int playerTurns;
int currentTurn;
char userInput;
bool validUserInput;
int playerOneScore = 0;
int playerTwoScore = 0;

int main()
{
	printIntro();
	showMenu();
	playGame();
}

void printIntro()
{
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|TAC|   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "   Let's play...\n\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "   TIC|TAC|TOE!\n";
	std::cout << "   ___|___|___\n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n";
	std::cout << "      |   |   \n\n";
	Sleep(2000);
	system("CLS");
}


void showMenu()
{
	system("CLS");
	std::cout << "TIC TAC TOE GAME\n\n";
	std::cout << "- Play New Game [N]\n";
	std::cout << "- How to Play [P]\n";
	std::cout << "- Scoreboard [S]\n";
	std::cout << "- Credits [C]\n\n";

	validUserInput = false;

	while (!validUserInput)
	{
		std::cin >> userInput;
		if (userInput == 'P' || userInput == 'p')
		{
			validUserInput = true;
			printInstructions();
		}
		else if (userInput == 'S' || userInput == 's')
		{
			validUserInput = true;
			showScoreboard();
		}
		else if (userInput == 'C' || userInput == 'c')
		{
			validUserInput = true;
			showCredits();
		}
		else if (userInput == 'N' || userInput == 'n')
		{
			validUserInput = true;
			return;
		}
		else
		{
			std::cout << "I'm sorry, I don't understand that command. Try again.\n";
		}
	}
}

void printInstructions()
{
	system("CLS");
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO PLAY  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO WIN!  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n\n";
	std::cout << "Press any key to return to the main menu...\n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO PLAY  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO WIN!  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |               |   |             X |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |             X |   |               |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n\n";
	std::cout << "Press any key to return to the main menu...\n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO PLAY  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO WIN!  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |               |   |             X |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |             X | X |               | X |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            |   |               |   |               |   |   \n\n";
	std::cout << "Press any key to return to the main menu...\n\n";
	Sleep(1000);
	system("CLS");
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO PLAY  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Two players take turns placing their marker, an [X] or an [O].\n";
	std::cout << "- Type a number on the grid and press \'Enter\' to place your marker there.\n\n";
	std::cout << "                               +---------------+\n";
	std::cout << "                               |  HOW TO WIN!  |\n";
	std::cout << "                               +---------------+\n\n";
	std::cout << "- Get three in a row vertically, horizontally or diagonally to win.\n\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |               |   |             X |   |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |             X | X | X             | X |   \n";
	std::cout << "         ___|___|___         ___|___|___         ___|___|___\n";
	std::cout << "            |   |               |   |               |   |   \n";
	std::cout << "            | X |               |   |               |   | X \n";
	std::cout << "            |   |               |   |               |   |   \n\n";

	std::cout << "Press any key to return to the main menu...\n\n";
	int keyPressed;
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...\n\n";
		_getch();
	}
}

void showScoreboard()
{
	system("CLS");
	std::cout << "                                +--------------+\n";
	std::cout << "                                |  SCOREBOARD  |\n";
	std::cout << "                                +--------------+\n\n";
	std::cout << "This feature is coming soon!\n\n";

	int keyPressed;
	std::cout << "Press any key to return to the main menu...\n\n";
	keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...\n\n";
		_getch();
	}
}

void showCredits()
{
	system("CLS");
	std::cout << "                                  +-----------+\n";
	std::cout << "                                  |  CREDITS  |\n";
	std::cout << "                                  +-----------+\n\n";
	std::cout << "This game was made by Tessa Power.\n\n";

	int keyPressed;
	std::cout << "Press any key to return to the main menu...\n\n";
		keyPressed = _getch();
	if (keyPressed)
	{
		showMenu();
	}
	else
	{
		std::cout << "Press any key to return to the main menu...\n\n";
		_getch();
	}
}

void playGame()
{
	setUpGame();
	drawCurrentGameState();

	do
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
		if (gameWon) {
			printWinningMessage();
			return;
		}
		else
		{
			currentTurn++;
		}
	} while (currentTurn < playerTurns && gameWon == false);

	if (!gameWon)
	{
		std::cout << "It's a draw! Better luck next time...\n\n";
	}

	askToPlayAgain();
}

void drawCurrentGameState()
{
	system("CLS");
	std::cout << "Player 1 [X] vs. Player 2 [O]\n";
	std::cout << "           " << playerOneScore << "  -  " << playerTwoScore << "\n\n";
	std::cout << "            |   |   \n";
	std::cout << "          " << gridLabels[1] << " | " << gridLabels[2] << " | " << gridLabels[3] << " \n";
	std::cout << "         ___|___|___\n";
	std::cout << "            |   |   \n";
	std::cout << "          " << gridLabels[4] << " | " << gridLabels[5] << " | " << gridLabels[6] << " \n";
	std::cout << "         ___|___|___\n";
	std::cout << "            |   |   \n";
	std::cout << "          " << gridLabels[7] << " | " << gridLabels[8] << " | " << gridLabels[9] << " \n";
	std::cout << "            |   |   \n\n";
}

void setUpGame()
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
	if ((gridLabels[1] == gridLabels[2]) && (gridLabels[2] == gridLabels[3]) ||
		(gridLabels[4] == gridLabels[5]) && (gridLabels[5] == gridLabels[6]) ||
		(gridLabels[7] == gridLabels[8]) && (gridLabels[8] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[4]) && (gridLabels[4] == gridLabels[7]) ||
		(gridLabels[2] == gridLabels[5]) && (gridLabels[5] == gridLabels[8]) ||
		(gridLabels[3] == gridLabels[6]) && (gridLabels[6] == gridLabels[9]) ||
		(gridLabels[1] == gridLabels[5]) && (gridLabels[5] == gridLabels[9]) ||
		(gridLabels[3] == gridLabels[5]) && (gridLabels[5] == gridLabels[7]))
	{
		gameWon = true;
	}
	else
	{
		gameWon = false;
	}
}

void printWinningMessage()
{
	if (currentTurn % 2 == 1)
	{
		std::cout << "> Player 1 wins! [X]\n\n";
		playerOneScore++;
	}
	else
	{
		std::cout << "> Player 2 wins! [O]\n\n";
		playerTwoScore++;
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
