//DataTables.hpp
#ifndef DATATABLES_HPP
#define DATATABLES_HPP

#include <Game/ResourceIdentifiers.hpp>

#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>

#include <vector>
#include <functional>

class Character;

struct Direction
{
	Direction(float angle, float distance)
	: angle(angle)
	, distance(distance)
	{
	}

	float angle;
	float distance;
};

struct CharacterData
{
	float 			speed;
	Textures::ID	texture;
	sf::IntRect		textureRect;
};

std::vector<CharacterData> 	initializeCharacterData();

#endif //DataTables.hpp