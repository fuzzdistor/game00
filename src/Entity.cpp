//Entity.cpp
#include <Game/Entity.hpp>

#include <cassert>

Entity::Entity()
: mVelocity()
, exists(true)
{	
}


void Entity::setVelocity(sf::Vector2f velocity) 
{ 
	mVelocity = velocity; 
};

void Entity::setVelocity(float vx, float vy) 
{ 
	mVelocity = {vx, vy}; 
};

sf::Vector2f Entity::getVelocity() const
{ 
	return mVelocity; 
};

void Entity::accelerate(sf::Vector2f velocity)
{
	mVelocity += velocity;
}

void Entity::accelerate(float vx, float vy)
{
	mVelocity += {vx, vy};
}

void Entity::destroy()
{
	exists = false;
}

void Entity::remove()
{
	destroy();
}

bool Entity::isDestroyed() const
{
	return exists;
}

void Entity::updateCurrent(sf::Time dt, CommandQueue&)
{
	move(mVelocity * dt.asSeconds());
}
