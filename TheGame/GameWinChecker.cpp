
#include "GameWinChecker.h"

const bool GameWinChecker::checkIfSymbolHasWon(char symbol, char gameGrid[])
{
	bool horizontalWin = ((gameGrid[1] == gameGrid[2]) && (gameGrid[2] == gameGrid[3]) ||
		(gameGrid[4] == gameGrid[5]) && (gameGrid[5] == gameGrid[6]) ||
		(gameGrid[7] == gameGrid[8]) && (gameGrid[8] == gameGrid[9]));

	bool verticalWin = ((gameGrid[1] == gameGrid[4]) && (gameGrid[4] == gameGrid[7]) ||
		(gameGrid[2] == gameGrid[5]) && (gameGrid[5] == gameGrid[8]) ||
		(gameGrid[3] == gameGrid[6]) && (gameGrid[6] == gameGrid[9]));

	bool diagonalWin = ((gameGrid[1] == gameGrid[5]) && (gameGrid[5] == gameGrid[9]) ||
		(gameGrid[3] == gameGrid[5]) && (gameGrid[5] == gameGrid[7]));

	return (horizontalWin || verticalWin || diagonalWin);
}
