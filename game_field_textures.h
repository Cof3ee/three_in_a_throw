#pragma once

#include <vector>

#include "tile_field.h"
#include "game_board_logic.h"

class game_field_textures
{
public:
	game_field_textures(const game_board_logic& game_field);

	
private:
	void pull_board_textures(const game_board_logic& game_field);

	std::vector<std::vector<tile_field>> board_textures;
};