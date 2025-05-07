#pragma once

#include <vector>

#include "board_element.h" 
#include "constants.h"

class game_board
{
public:
	game_board(const  int &rows, const  int& cols);

	void check_three_in_throw();

	bool swap_elemnts(const board_element& first, const board_element& second);

	std::vector<std::vector< int>> get_board();

#ifdef DEBUG
	void display();
#endif 
private:
	void fill_board_random_values();

	 int generate_random_number();

	bool has_three_consecutive_equal(const std::vector< int>& row);

	bool check_three_in_a_row();

	bool check_three_in_a_col();

	void replace_three_consecutive_equal(std::vector< int>& row);

private:
	std::vector<std::vector< int>> board_;
	int num_rows_;
	int num_cols_;
};

