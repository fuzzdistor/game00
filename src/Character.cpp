//Character.cpp
#include <Game/Character.hpp>
#include <Game/DataTables.hpp>
#include <Game/Utility.hpp>
#include <Game/CommandQueue.hpp>
#include <Game/SoundNode.hpp>
#include <Game/ResourceHolder.hpp>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>

#include <cmath>

using namespace std::placeholders;

namespace 
{
	const std::vector<CharacterData> Table = initializeCharacterData();
}

Character::Character(Type type, const TextureHolder& textures, const FontHolder& fonts)
: Entity()
, mType(type)
, mSprite(textures.get(Table[type].texture), Table[type].textureRect)
{
	centerOrigin(mSprite);

	std::unique_ptr<TextNode> nameDisplay(new TextNode(fonts, ""));
	mNameDisplay = nameDisplay.get();
	attachChild(std::move(nameDisplay));

	mNameDisplay->setString("Ghost");
}

void Character::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mSprite);
}

void Character::updateCurrent(sf::Time dt, CommandQueue& commands)
{
	Entity::updateCurrent(dt, commands);
}

unsigned int Character::getCategory() const
{
	if (mType == Ghost)
		return Category::PlayerCharacter;
	else
		return Category::NPCharacter;
}

void Character::remove()
{
	Entity::remove();
}

float Character::getMaxSpeed() const
{
	return Table[mType].speed;
}

void Character::playLocalSound(CommandQueue& commands, SoundEffect::ID effect)
{
	sf::Vector2f worldPosition = getWorldPosition();
	
	Command command;
	command.category = Category::SoundEffect;
	command.action = derivedAction<SoundNode>(
		[effect, worldPosition] (SoundNode& node, sf::Time)
		{
			node.playSound(effect, worldPosition);
		});

	commands.push(command);
}
