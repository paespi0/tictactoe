// TheGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{

	int gridNumber;

	std::cout << "| 1 | 2 | 3 |\n";
	std::cout << "| 4 | 5 | 6 |\n";
	std::cout << "| 7 | 8 | 9 |\n\n";

	int playerTurns = 9;
	int currentTurn = 0;

	
	while (currentTurn < playerTurns)
	{
		std::cout << "Type a number on the grid and press Enter to place your x there.\n";
		std::cin >> gridNumber;
	
		switch (gridNumber)
		{
		case 1: std::cout << "| x | 2 | 3 |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 2: std::cout << "| 1 | x | 3 |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 3: std::cout << "| 1 | 2 | x |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 4: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| x | 5 | 6 |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 5: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| 4 | x | 6 |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 6: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| 4 | 5 | x |\n";
			std::cout << "| 7 | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 7: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| x | 8 | 9 |\n\n";
			currentTurn++;
			break;
		case 8: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| 7 | x | 9 |\n\n";
			currentTurn++;
			break;
		case 9: std::cout << "| 1 | 2 | 3 |\n";
			std::cout << "| 4 | 5 | 6 |\n";
			std::cout << "| 7 | 8 | x |\n\n";
			currentTurn++;
			break;
		default: std::cout << "That doesn't seem right! Try again.\n\n";
		}

		std::cout << "The current turn is:" << currentTurn << std::endl;
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
