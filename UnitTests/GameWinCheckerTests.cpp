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
			char playerSymbol = 'X';
			char gameState[] = {
				'0', 'O', '2',
				'X', 'X', 'X',
				'6', '7', 'O',
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
			char playerSymbol = 'X';
			char gameState[] = {
				'O', 'X', '2',
				'3', 'X', '5',
				'O', 'X', '8',
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
			char playerSymbol = 'X';
			char gameState[] = {
				'X', '1', '2',
				'O', 'X', '5',
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
				'0', '1', '2', 
				'3', '4', '5',
				'6', '7', '8',
				'\0'};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfEmptyGrid\' failed.");
		}

		TEST_METHOD(ExpectNotWonIfDraw)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'X', 'O', 'X',
				'X', 'X', 'O',
				'O', 'X', 'O',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfDraw\' failed.");
		}

		TEST_METHOD(ExpectNotWonIfNotEnoughMovesYet)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'X', '1', '2',
				'3', 'O', '5',
				'6', '7', '8',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfNotEnoughMovesYet\' failed.");
		}

		TEST_METHOD(ExpectNotWonIfSymbolIsNotPlayerMarker)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'@', 'X', '2',
				'O', '@', '5',
				'X', '7', '@',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfSymbolIsForeign\' failed.");
		}

		TEST_METHOD(ExpectNotWonIfSymbolIsLosingPlayerMarker)
		{
			// Arrange
			char playerSymbol = 'O';
			char gameState[] = {
				'X', '1', '2',
				'O', 'X', '5',
				'X', 'O', 'X',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfSymbolIsLosingPlayerMarker\' failed.");
		}

	};

	//TEST_CLASS(MoveValidator)
	//{
	//public:

	//	TEST_METHOD(validatePlayerMove)
	//	{
	//		Assert::IsTrue(false);
	//	}
	//};
}


/* Note to Self:
You will only be able to unit test public functions this way.
To unit test private functions, you must write your unit tests
in the same class as the code that is being tested.
*/