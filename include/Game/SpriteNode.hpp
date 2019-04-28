//SpriteNode.hpp
#ifndef SPRITENODE_HPP
#define SPRITENODE_HPP

#include <Game/SceneNode.hpp>

#include <SFML/Graphics/Sprite.hpp>

class SpriteNode : public SceneNode
{
public:
					SpriteNode(const sf::Texture& texture, const sf::IntRect& textureRect);
	explicit 		SpriteNode(const sf::Texture& texture);


private:
	virtual void 	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Sprite		mSprite;
};

#endif //SpriteNode.hpp
