//TextNode.hpp
#ifndef TEXTNODE_HPP
#define TEXTNODE_HPP

#include <Game/ResourceHolder.hpp>
#include <Game/ResourceIdentifiers.hpp>
#include <Game/SceneNode.hpp>

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>


class TextNode : public SceneNode
{
public:
	explicit		TextNode(const FontHolder& fonts, const std::string& text);


public:
	void 		setString(const std::string& text);


private:
	virtual void 	drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


private:
	sf::Text		mText;
};

#endif //TextNode.hpp
