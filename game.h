#pragma once

#include "game_board.h"
#include "board_element.h"

class game
{
public:
	game(const unsigned& rows, const unsigned int& cols);

	void make_move(const board_element &first, const board_element &second);

	void display(); //Временно для отладки

	std::vector<std::vector<unsigned int>> get_board();

private:
	game_board board_;
};

