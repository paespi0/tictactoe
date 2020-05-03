
#include "GameWinChecker.h"

const bool GameWinChecker::checkIfSymbolHasWon(char symbol, char gameBoard[])
{
	bool horizontalWin = (gameBoard[0] == symbol && gameBoard[1] == symbol && gameBoard[2] == symbol ||
		gameBoard[3] == symbol && gameBoard[4] == symbol && gameBoard[5] == symbol ||
		gameBoard[6] == symbol && gameBoard[7] == symbol && gameBoard[8] == symbol);

	bool verticalWin = (gameBoard[0] == symbol && gameBoard[3] == symbol && gameBoard[6] == symbol ||
		gameBoard[1] == symbol && gameBoard[4] == symbol && gameBoard[7] == symbol ||
		gameBoard[2] == symbol && gameBoard[5] == symbol && gameBoard[8] == symbol);

	bool diagonalWin = (gameBoard[0] == symbol && gameBoard[4] == symbol && gameBoard[8] == symbol ||
		gameBoard[2] == symbol && gameBoard[4] == symbol && gameBoard[6] == symbol);

	return (horizontalWin || verticalWin || diagonalWin);
}
