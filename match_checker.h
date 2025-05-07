#pragma once

#include <vector>

class match_checker
{
public:
	bool check_match();

private:
	bool check_three_in_a_row();

	bool check_three_in_a_col();

	bool has_three_consecutive_equal(const std::vector<int>& row);
};