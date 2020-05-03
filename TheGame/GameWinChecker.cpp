
#include "GameWinChecker.h"

const bool GameWinChecker::checkIfSymbolHasWon(char symbol, char gameGrid[])
{
	bool horizontalWin = (gameGrid[1] == symbol && gameGrid[2] == symbol && gameGrid[3] == symbol ||
		gameGrid[4] == symbol && gameGrid[5] == symbol && gameGrid[6] == symbol ||
		gameGrid[7] == symbol && gameGrid[8] == symbol && gameGrid[9] == symbol);

	bool verticalWin = (gameGrid[1] == symbol && gameGrid[4] == symbol && gameGrid[7] == symbol ||
		gameGrid[2] == symbol && gameGrid[5] == symbol && gameGrid[8] == symbol ||
		gameGrid[3] == symbol && gameGrid[6] == symbol && gameGrid[9] == symbol);

	bool diagonalWin = (gameGrid[1] == symbol && gameGrid[5] == symbol && gameGrid[9] == symbol ||
		gameGrid[3] == symbol && gameGrid[5] == symbol && gameGrid[7] == symbol);

	return (horizontalWin || verticalWin || diagonalWin);
}
