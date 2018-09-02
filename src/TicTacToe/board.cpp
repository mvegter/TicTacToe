#include "pch.h"
#include "board.h"
#include <iostream>

char grid[10];

int player1_won;

int player2_won;

board::board() = default;

board::~board() = default;

bool board::has_winner()
{
	// Horizontal
	if (grid[1] == grid[2] && grid[2] == grid[3])
	{
		return true;
	}
	if (grid[4] == grid[5] && grid[5] == grid[6])
	{
		return true;
	}
	if (grid[7] == grid[8] && grid[8] == grid[9])
	{
		return true;
	}

	// Vertical
	if (grid[1] == grid[4] && grid[4] == grid[7])
	{
		return true;
	}
	if (grid[2] == grid[5] && grid[5] == grid[8])
	{
		return true;
	}
	if (grid[3] == grid[6] && grid[6] == grid[9])
	{
		return true;
	}

	// Diagonal
	if (grid[1] == grid[5] && grid[5] == grid[9])
	{
		return true;
	}

	if (grid[7] == grid[5] && grid[5] == grid[3])
	{
		return true;
	}

	return false;
}

void build_header()
{
	system("CLS");

	std::cout << "Welcome to console-based Tic-Tac-Toe!" << std::endl;
	if (player1_won + player2_won > 0)
	{
		std::cout << "Stats: Player 1 won " << player1_won << " time" << (player1_won > 1 || player1_won == 0 ? "s" : "") << ", ";
		std::cout << "Player 2 won " << player2_won << " time" << (player2_won > 1 || player2_won == 0 ? "s" : "") << "." << std::endl;
	}

	std::cout << std::endl;
}

void initialize_grid()
{
	grid[0] = '0';
	grid[1] = '1';
	grid[2] = '2';
	grid[3] = '3';
	grid[4] = '4';
	grid[5] = '5';
	grid[6] = '6';
	grid[7] = '7';
	grid[8] = '8';
	grid[9] = '9';
}

void build_grid()
{
	if (grid[0] == NULL)
	{
		initialize_grid();
	}

	build_header();

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
}

void reset_grid()
{
	for (auto& i : grid)
	{
		i = NULL;
	}
}

void board::start_game()
{
	reset_grid();
	build_grid();

	auto turn = 0;
	auto end = false;
	do
	{
		do
		{
			build_grid();

			int input;
			std::cout << "Player " << (turn % 2 == 0 ? '1' : '2') << ", input: ";
			std::cin >> input;

			auto& block = grid[input];
			if (input == 0 || block == 'X' || block == 'O')
			{
				continue;
			}

			block = turn % 2 == 0 ? 'X' : 'O';
			break;
		}
		while (true);

		if (has_winner())
		{
			end = has_winner();
		}
		else
		{
			turn++;
		}
	}
	while (!end);

	build_grid();

	std::cout << std::endl;
	std::cout << "Winner of this game is: Player " << (turn % 2 == 0 ? "1" : "2") << std::endl;

	turn % 2 == 0 ? player1_won++ : player2_won++;
}
