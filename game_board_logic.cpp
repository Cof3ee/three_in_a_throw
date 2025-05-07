#include "game_board_logic.h"

game_board_logic::game_board_logic(const int &rows,const int &cols) : board_(rows,cols)
{}

void game_board_logic::make_move(const board_element &first, const board_element &second)
{
	board_.swap_elemnts(first,second); //Меняем элементы по координатам 
	
	board_.check_three_in_throw(); //Проверяем появилось ли 3 в ряд
}

void game_board_logic::display()
{
	board_.display();
}

std::vector<std::vector< int>> game_board_logic::get_board()
{
	return board_.get_board();
}

