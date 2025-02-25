#include "game_board.h"

#include <random>
#include <iostream> //Временно 

using namespace std;

game_board::game_board(const unsigned int& rows, const unsigned int& cols) : rows_(rows), cols_(cols)
{
	fill_board();
	
	check_three_in_a_row();
}

void game_board::display()
{
	int r = 0;
	for (const auto& row : board_)
	{
		cout << "row " << r << ": ";
		for (int val : row)
		{
			std::cout << val << " ";
		}
		std::cout << std::endl;
		r++;
	}
}

void game_board::fill_board()
{
	for (size_t i = 0; i < rows_; i++)
	{
		vector<unsigned int> rows;

		for (size_t i = 0; i < cols_; i++)
		{
			rows.push_back(generate_random_number());
		}
		board_.push_back(rows);
	}
}

unsigned int game_board::generate_random_number()
{
	/*unsigned int random_number;

	srand(time(NULL));

	return random_number = rand() % 3;*/

	
	std::random_device rd;  // Источник случайности
	std::mt19937 gen(rd()); // Mersenne Twister engine, инициализированный случайным зерном

	// Создаем распределение для диапазона [0, 2]
	std::uniform_int_distribution<> distrib(0, 2);

	// Генерируем случайное число
	return distrib(gen);
}

void game_board::check_three_in_a_row()
{
	for (size_t index = 0; index < board_.size();)
	{
		if (check_row(board_[index]))
		{
			do
			{
				replace_three_in_a_row(board_[index]);

			} while (check_row(board_[index]));
		}
		index++;
	}
}

bool game_board::check_row(const vector<unsigned int>& row)
{
	for (size_t i = 0; i <= row.size() - 3; ++i) 
	{ // Проходим до предпоследнего элемента
		if (row[i] == row[i + 1] && row[i] == row[i + 2]) 
		{
			// Найдено три одинаковых числа подряд
			return true;
		}
	}

	// Не найдено три одинаковых числа подряд
	return false;
}

void game_board::replace_three_in_a_row( std::vector<unsigned int>& row)
{
	for (size_t i = 0; i <= row.size() - 3; ++i) 
	{
		if (row[i] == row[i + 1] && row[i] == row[i + 2]) //ДЛЯ ЭТОЙ ПРОВЕРКИ НУЖНА ОТДЕЛЬНАЯ ФУНКЦИЯ, Т К ОНА ПОВТОРЯЕТСЯ
		{
			// Найдено три одинаковых числа подряд
			unsigned int newValue1, newValue2, newValue3;

			// Генерируем новые значения, отличные от текущего
			//do 
			//{
				newValue1 = generate_random_number();
			//} while (newValue1 == row[i]);

			//do 
			//{
				newValue2 = generate_random_number();
			//} while (newValue2 == row[i]);

			//do 
			//{
				newValue3 = generate_random_number();
			//} while (newValue3 == row[i]);


			row[i] = newValue1;
			row[i + 1] = newValue2;
			row[i + 2] = newValue3;

		}
	}
}

bool game_board::swap_elemnts(const board_element& first, const board_element& second)
{
	//ОРГАНИЗОВАТЬ ПРОВЕРКУ В ОТДЕЛЬНУЮ ФУНКЦИЮ
	// Проверяем, что координаты находятся в пределах границ поля
	if (first.row < 0 || first.row >= rows_ || first.col < 0 || first.col >= cols_ ||
		second.row < 0 || second.row >= rows_ || second.col < 0 || second.col >= cols_)
	{
		std::cerr << "Error: Invalid coordinates for swap." << std::endl;
		return false; // Координаты вне допустимого диапазона
	}

	// Меняем элементы местами
	std::swap(board_[first.row][first.col], board_[second.row][second.col]);
	return true; // Успешно поменяли элементы
}

vector<vector<unsigned int>> game_board::get_board()
{
	return board_;
}

