#include "game_board.h"

#include <random>
#include <iostream> //�������� 

using namespace std;

game_board::game_board(const  int& rows, const  int& cols) : rows_(rows), cols_(cols)
{
	fill_board();
	check_three_in_throw();
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

void game_board::check_three_in_throw()
{
	do
	{
		 check_three_in_a_row();
		 check_three_in_a_col();
	} while (check_three_in_a_row()&& check_three_in_a_col());
}

void game_board::fill_board()
{
	for (size_t i = 0; i < rows_; i++)
	{
		vector< int> rows;

		for (size_t i = 0; i < cols_; i++)
		{
			rows.push_back(generate_random_number());
		}
		board_.push_back(rows);
	}
}

 int game_board::generate_random_number()
{
	std::random_device rd;  // �������� �����������
	std::mt19937 gen(rd()); // Mersenne Twister engine, ������������������ ��������� ������

	// ������� ������������� ��� ��������� [0, 2]
	std::uniform_int_distribution<> distrib(0, 2);

	// ���������� ��������� �����
	return distrib(gen);
}

bool game_board::check_three_in_a_row()
{
	bool argument = false;
	for (size_t index = 0; index < board_.size();)
	{
		if (has_three_consecutive_equal(board_[index]))
		{
			replace_three_consecutive_equal(board_[index]);
			argument = true;
		}
		index++;
	}
	return argument;
}

bool game_board::has_three_consecutive_equal(const vector< int>& row)
{
	for (size_t index = 0; index <= row.size() - 3; ++index) 
	{ // �������� �� �������������� ��������
		if (row[index] == row[index + 1] && row[index] == row[index + 2]) 
		{
			// ������� ��� ���������� ����� ������
			return true;
		}
	}
	// �� ������� ��� ���������� ����� ������
	return false;
}

bool game_board::check_three_in_a_col()
{
	bool argument = false;
	for(size_t index_col=0; index_col< cols_;++index_col)
	{
		vector <int>value_in_cols;
		for (size_t index_row = 0; index_row < rows_; ++index_row)
		{
			value_in_cols.push_back(board_[index_row][index_col]);
		}
		
		if (has_three_consecutive_equal(value_in_cols))
		{
			do
			{
				replace_three_consecutive_equal(value_in_cols);
			} while (has_three_consecutive_equal(value_in_cols));

			for (size_t index_row = 0; index_row < rows_; ++index_row)
			{
				board_[index_row][index_col] = value_in_cols[index_row];
			}

			argument = true;
		}
	}
	return argument;
}

void game_board::replace_three_consecutive_equal( std::vector< int>& row)
{
	for (size_t i = 0; i <= row.size() - 3; ++i) 
	{
		if (row[i] == row[i + 1] && row[i] == row[i + 2]) 
		{
			 int newValue1, newValue2, newValue3;

			newValue1 = generate_random_number();
			newValue2 = generate_random_number();
			newValue3 = generate_random_number();

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

vector<vector< int>> game_board::get_board()
{
	return board_;
}

