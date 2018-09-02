#pragma once
class board
{
public:
	board();

	~board();

	static bool has_winner();

	static void start_game();
};
