#include "pch.h"
#include "CppUnitTest.h"
#include "../TheGame/GameWinChecker.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace GameWinCheckerTests
{
	TEST_CLASS(checkIfSymbolHasWon)
	{
	public:
		
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