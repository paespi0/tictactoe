#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameWinChecker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameWinCheckerTests
{
	TEST_CLASS(checkIfSymbolHasWon)
	{
	public:
		
		TEST_METHOD(ExpectWonIfSymbolFillsHorizontalRow)
		{
			// Arrange
			char playerSymbol = 'X'; // currently not using symbol to check winning combination
			char gameState[] = {
				'0',
				'1', 'O', '3',
				'X', 'X', 'X',
				'7', '8', 'O',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"Unit test \'ExpectWonIfSymbolFillsHorizontalRow\' failed.");
		}

		TEST_METHOD(ExpectWonIfSymbolFillsVerticalRow)
		{
			// Arrange
			char playerSymbol = 'X'; // currently not using symbol to check winning combination
			char gameState[] = {
				'0',
				'O', 'X', '3',
				'4', 'X', '6',
				'O', 'X', '9',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"Unit test \'ExpectWonIfSymbolFillsVerticalRow\' failed.");
		}

		TEST_METHOD(ExpectWonIfSymbolFillsDiagonalRow)
		{
			// Arrange
			char playerSymbol = 'X'; // currently not using symbol to check winning combination
			char gameState[] = {
				'0',
				'X', '2', '3',
				'O', 'X', '6',
				'X', 'O', 'X',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsTrue(gameWon, L"Unit test \'ExpectWonIfSymbolFillsDiagonalRow\' failed.");
		}

		TEST_METHOD(ExpectNotWonIfEmptyGrid)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'0',
				'1', '2', '3', 
				'4', '5', '6',
				'7', '8', '9',
				'\0'};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Computer said no");
		}
	};

	TEST_CLASS(MoveValidator)
	{
	public:

		TEST_METHOD(validatePlayerMove)
		{
			Assert::IsTrue(false);
		}
	};
}


/* Note to Self:
You will only be able to unit test public functions this way.
To unit test private functions, you must write your unit tests
in the same class as the code that is being tested.
*/