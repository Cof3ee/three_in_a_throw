#include "game_board.h"

#include <random>
#include <iostream> //�������� 

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

	
	std::random_device rd;  // �������� �����������
	std::mt19937 gen(rd()); // Mersenne Twister engine, ������������������ ��������� ������

	// ������� ������������� ��� ��������� [0, 2]
	std::uniform_int_distribution<> distrib(0, 2);

	// ���������� ��������� �����
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
	{ // �������� �� �������������� ��������
		if (row[i] == row[i + 1] && row[i] == row[i + 2]) 
		{
			// ������� ��� ���������� ����� ������
			return true;
		}
	}

	// �� ������� ��� ���������� ����� ������
	return false;
}

void game_board::replace_three_in_a_row( std::vector<unsigned int>& row)
{
	for (size_t i = 0; i <= row.size() - 3; ++i) 
	{
		if (row[i] == row[i + 1] && row[i] == row[i + 2]) //��� ���� �������� ����� ��������� �������, � � ��� �����������
		{
			// ������� ��� ���������� ����� ������
			unsigned int newValue1, newValue2, newValue3;

			// ���������� ����� ��������, �������� �� ��������
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
	//������������ �������� � ��������� �������
	// ���������, ��� ���������� ��������� � �������� ������ ����
	if (first.row < 0 || first.row >= rows_ || first.col < 0 || first.col >= cols_ ||
		second.row < 0 || second.row >= rows_ || second.col < 0 || second.col >= cols_)
	{
		std::cerr << "Error: Invalid coordinates for swap." << std::endl;
		return false; // ���������� ��� ����������� ���������
	}

	// ������ �������� �������
	std::swap(board_[first.row][first.col], board_[second.row][second.col]);
	return true; // ������� �������� ��������
}

vector<vector<unsigned int>> game_board::get_board()
{
	return board_;
}

