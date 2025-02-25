#pragma once

#include <vector>

#include "board_element.h" 

class game_board
{
public:
	game_board(const unsigned int &rows, const unsigned int& cols);

	void display();

	void check_three_in_a_row();

	bool swap_elemnts(const board_element& first, const board_element& second);

	std::vector<std::vector<unsigned int>> get_board();
private:
	void fill_board();

	unsigned int generate_random_number();

	bool check_row(const std::vector<unsigned int>& row);

	void replace_three_in_a_row(std::vector<unsigned int>& row);

private:
	std::vector<std::vector<unsigned int>> board_;
	
	unsigned int rows_;
	unsigned int cols_;
};

