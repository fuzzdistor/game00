//Entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <SFML/Graphics.hpp>


class Entity
{
public:
    void    setVelocity(sf::Vector2f velocity);
    void    setVelocity(float vx, float vy);

    sf::Vector2f getVelocity();

private:
    sf::Vector2f mVelocity;

};

#endif