#include "game.h"

game::game(const unsigned &rows,const unsigned int &cols) : board_(rows,cols)
{

}

void game::make_move(const board_element &first, const board_element &second)
{
	board_.swap_elemnts(first,second); //Меняем элементы по координатам 
	
	board_.check_three_in_a_row(); //Проверяем появилось ли 3 в ряд
}

void game::display()
{
	board_.display();
}

std::vector<std::vector<unsigned int>> game::get_board()
{
	return board_.get_board();
}

