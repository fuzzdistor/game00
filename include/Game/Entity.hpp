//Entity.hpp
#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <Game/SceneNode.hpp>


class Entity : public SceneNode
{
public:
	explicit 		Entity();


public:
	void		setVelocity(sf::Vector2f velocity);
	void 		setVelocity(float vx, float vy);
	void 		accelerate(sf::Vector2f velocity);
	void 		accelerate(float vx, float vy);

	sf::Vector2f 	getVelocity() const;

	void 			destroy();
	virtual void	remove();
	virtual bool 	isDestroyed() const;

protected:
	virtual void	updateCurrent(sf::Time time, CommandQueue& commands);


private:
	sf::Vector2f 	mVelocity;
	bool 			exists;
};

#endif
