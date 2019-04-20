//Entity.cpp
#include <SFML/Graphics.hpp>
#include "Entity.hpp"


void Entity::setVelocity(sf::Vector2f velocity) { mVelocity = velocity; };

void Entity::setVelocity(float vx, float vy) { mVelocity = {vx, vy}; };

sf::Vector2f Entity::getVelocity() { return mVelocity; };

