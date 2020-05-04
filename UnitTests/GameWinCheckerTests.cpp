#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameWinChecker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameWinCheckerTests
{
	TEST_CLASS(checkIfSymbolHasWon)
	{
	public:
		
		TEST_METHOD(ExpectWon_SymbolFillsHorizontalRow)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
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

		TEST_METHOD(ExpectWon_SymbolFillsVerticalRow)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
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

		TEST_METHOD(ExpectWon_SymbolFillsDiagonalRow)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
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

		TEST_METHOD(ExpectNotWon_GameStateEmpty)
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'1', '2', '3',
				'4', '5', '6',
				'7', '8', '9',
				'\0'};

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);


			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfEmptyGrid\' failed.");
		}

		TEST_METHOD(ExpectNotWon_GameStateDraw)
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

		TEST_METHOD(ExpectNotWon_IfNotEnoughMovesYet) // Name formula: Expect[Outcome]_GameState[condition]_Symbol[condition]
		{
			// Arrange
			char playerSymbol = 'X';
			char gameState[] = {
				'X', '2', '3',
				'4', 'O', '6',
				'7', '8', '9',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(playerSymbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Unit test \'ExpectNotWonIfNotEnoughMovesYet\' failed.");
		}
		// Name formula: Expect[Outcome]_GameState[condition]_Symbol[condition]
		TEST_METHOD(ExpectNotWon_GameStateContainsWin_SymbolIsNotWinningSymbol)
		{
			// Arrange
			char symbol = 'O';
			char gameState[] = {
				'X', '2', '3',
				'O', 'X', '6',
				'X', 'O', 'X',
				'\0' };

			// Act
			GameWinChecker gameWinChecker;
			bool gameWon = gameWinChecker.checkIfSymbolHasWon(symbol, gameState);

			// Assert
			Assert::IsFalse(gameWon, L"Extra information goes here...");
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