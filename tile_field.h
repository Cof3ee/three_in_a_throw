#pragma once

#include <SFML/Graphics.hpp>

struct tile_field
{
	sf::RectangleShape field_texture;
	int field_name_number;
	bool field_color = false;
};
