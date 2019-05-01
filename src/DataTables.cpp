//DataTables.cpp
#include <Game/DataTables.hpp>
#include <Game/Character.hpp>

using namespace std::placeholders;

std::vector<CharacterData> initializeCharacterData()
{
	std::vector<CharacterData> data(Character::TypeCount);

	data[Character::Ghost].speed = 100;
	data[Character::Ghost].texture = Textures::Entities;
	data[Character::Ghost].textureRect = sf::IntRect(0, 0, 48, 64);

	data[Character::Exorcist].speed = 100;
	data[Character::Exorcist].texture = Textures::Entities;
	data[Character::Exorcist].textureRect = sf::IntRect(144, 0, 84, 64);

	return data;
}
