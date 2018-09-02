// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	char grid[10];
	grid[1] = '1';
	grid[2] = '2';
	grid[3] = '3';
	grid[4] = '4';
	grid[5] = '5';
	grid[6] = '6';
	grid[7] = '7';
	grid[8] = '8';
	grid[9] = '9';

	auto turn = 0;
	auto end = false;
	do
	{
		auto valid_input = false;

		do
		{
			system("CLS");

			std::cout << "Welcome to console-based Tic-Tac-Toe!" << std::endl;
			std::cout << std::endl;

			for (auto i = 1; i < sizeof grid / sizeof grid[0]; ++i)
			{
				std::cout << " " << grid[i];
				if (i % 3 == 0)
				{
					std::cout << std::endl;
				}
				else
				{
					std::cout << " | ";
				}
			}

			std::cout << std::endl;

			int input;
			std::cout << "Player " << (turn % 2 == 0 ? '1' : '2') << ", input: ";
			std::cin >> input;

			auto& block = grid[input];
			if (input == 0 || block == 'X' || block == 'O')
			{
				continue;
			}
			valid_input = true;

			block = turn % 2 == 0 ? 'X' : 'O';
		}
		while (!valid_input);

		// Horizontal

		if (grid[1] == grid[2] && grid[2] == grid[3])
		{
			end = true;
		}

		else if (grid[4] == grid[5] && grid[5] == grid[6])
		{
			end = true;
		}

		else if (grid[7] == grid[8] && grid[8] == grid[9])
		{
			end = true;
		}

			// Vertical

		else if (grid[1] == grid[4] && grid[4] == grid[7])
		{
			end = true;
		}

		else if (grid[2] == grid[5] && grid[5] == grid[8])
		{
			end = true;
		}

		else if (grid[3] == grid[6] && grid[6] == grid[9])
		{
			end = true;
		}

			// Diagonal

		else if (grid[1] == grid[5] && grid[5] == grid[9])
		{
			end = true;
		}

		else if (grid[7] == grid[5] && grid[5] == grid[3])
		{
			end = true;
		}

			// Next

		else
		{
			turn++;
		}
	}
	while (!end);

	system("CLS");

	std::cout << "Welcome to console-based Tic-Tac-Toe!" << std::endl;
	std::cout << std::endl;

	for (auto i = 1; i < sizeof grid / sizeof grid[0]; ++i)
	{
		std::cout << " " << grid[i];
		if (i % 3 == 0)
		{
			std::cout << std::endl;
		}
		else
		{
			std::cout << " | ";
		}
	}

	std::cout << std::endl;
	std::cout << "Winner of this game is: Player " << (turn % 2 == 0 ? "1" : "2");
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
