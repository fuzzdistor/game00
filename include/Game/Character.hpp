//Character.hpp
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <Game/Entity.hpp>
#include <Game/Command.hpp>
#include <Game/ResourceIdentifiers.hpp>
#include <Game/TextNode.hpp>
#include <Game/Animation.hpp>


#include <SFML/Graphics/Sprite.hpp>

class Character : public Entity
{
public:
	enum Type
	{
		Ghost,
		Exorcist,
		TypeCount,
	};


public:
	Character(Type type, const TextureHolder& textures, const FontHolder& fonts);


public:
	virtual unsigned int	getCategory() const;
	virtual sf::FloatRect	getBoundingRect() const;
	
	virtual void		remove();
	
	float 				getMaxSpeed() const;

private:
	virtual void 		drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;
	virtual void 		updateCurrent(sf::Time dt, CommandQueue& commands);

	void 		playLocalSound(CommandQueue& commands, SoundEffect::ID effect);

private:
	Type		mType;
	sf::Sprite	mSprite;
	TextNode* 	mNameDisplay;
};

#endif //Character.hpp