#pragma once

#include "game_board.h"
#include "board_element.h"

class game_board_logic
{
public:
	game_board_logic(const int& rows, const int& cols);

	void make_move(const board_element &first, const board_element &second);

	void display(); //Временно для отладки

	std::vector<std::vector<int>> get_board();

private:
	game_board board_;
};

