#pragma once

#include "game_board.h"
#include "board_element.h"

class game
{
public:
	game(const int& rows, const int& cols);

	void make_move(const board_element &first, const board_element &second);

	void display(); //Временно для отладки

	std::vector<std::vector<int>> get_board();

private:
	game_board board_;
};

